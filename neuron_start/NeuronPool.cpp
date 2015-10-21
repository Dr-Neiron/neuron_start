#include "NeuronPool.h"
#include "Neuron.h"
#include "SensorNeuron.h"
#include "OutNeuron.h"
#include <random>

NeuronPool::NeuronPool(const Config& configurator) :
    _size(0),
    _config(configurator)
{
}

NeuronPool::~NeuronPool()
{
    for (size_t i = 0; i < _neurons.size(); ++i)
        delete _neurons[i];
    _neurons.clear();
    for (size_t i = 0; i < _sensorNeurons.size(); ++i)
        delete _sensorNeurons[i];
    _sensorNeurons.clear();
    for (size_t i = 0; i < _outNeurons.size(); ++i)
        delete _outNeurons[i];
    _outNeurons.clear();
}

void NeuronPool::construct()
{
    _config.log() << __FUNCTIONW__ << L": Constructing neuron pool.\n";

    // create sensor neurons
    _sensorNeurons.reserve(_config.getSensorNeuronCount());
    for (size_t i = 0; i < _config.getSensorNeuronCount(); ++i)
    {
        INeuron* n = new SensorNeuron(_config);
        _sensorNeurons.push_back(n);
    }

    // create middle neurons
    _neurons.reserve(_config.getMiddleNeuronCount());
    for (size_t i = 0; i < _config.getMiddleNeuronCount(); ++i)
    {
        INeuron* n = new Neuron(_config);
        _neurons.push_back(n);
    }

    // create out neurons
    _outNeurons.reserve(_config.getOutNeuronCount());
    for (size_t i = 0; i < _config.getOutNeuronCount(); ++i)
    {
        INeuron* n = new OutNeuron(_config);
        _outNeurons.push_back(n);
    }

    static std::default_random_engine randomGenerator;
    static std::uniform_real_distribution<double> weightDistribution(0.0, 1.0);
    static std::uniform_int_distribution<size_t> middleNeuronsDistribution(0, _config.getMiddleNeuronCount() - 1);

    // create sensor synapses
    for (size_t i = 0; i < _config.getSensorNeuronCount(); ++i)
    {
        size_t to = middleNeuronsDistribution(randomGenerator);
        double weight = 1.0;
        _sensorNeurons[i]->setNewSynapse(Synapse(_neurons[to], weight));
    }

    // create middle synapses
    for (size_t i = 0; i < _config.getMiddleSynapseCount(); ++i)
    {
        size_t from = middleNeuronsDistribution(randomGenerator);
        size_t to = middleNeuronsDistribution(randomGenerator);
        double weight = weightDistribution(randomGenerator);
        _neurons[from]->setNewSynapse(Synapse(_neurons[to], weight));
    }

    // create out synapses
    for (size_t outNeuronIndex = 0; outNeuronIndex < _config.getOutNeuronCount(); ++outNeuronIndex)
    {
        for (size_t synapseIndex = 0; synapseIndex < _config.getOutSynapseCount(); ++synapseIndex)
        {
            size_t from = middleNeuronsDistribution(randomGenerator);
            double weight = weightDistribution(randomGenerator);
            _neurons[from]->setNewSynapse(Synapse(_outNeurons[outNeuronIndex], weight));
        }
    }
}

void NeuronPool::process()
{
    for (size_t i = 0; i < _sensorNeurons.size(); ++i)
        _sensorNeurons[i]->process();
    for (size_t i = 0; i < _neurons.size(); ++i)
        _neurons[i]->process();
    for (size_t i = 0; i < _outNeurons.size(); ++i)
        _outNeurons[i]->process();
}

void NeuronPool::lockSynapseWeights(bool isLocked)
{
    for (auto neuron : _neurons)
        neuron->lockSynapseWeights(isLocked);
}

std::vector<INeuron*> NeuronPool::getSensorNeurons() const
{
    return _sensorNeurons;
}

std::vector<INeuron*> NeuronPool::getOutNeurons() const
{
    return _outNeurons;
}

