#include "NeuronPool.h"
#include "Neuron.h"
#include "SensorNeuron.h"
#include "OutNeuron.h"
#include <random>

NeuronPool::NeuronPool(const Config& configurator) :
    _size(0),
    _configurator(configurator)
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
    // create sensor neurons
    _sensorNeurons.reserve(_configurator.getSensorNeuronCount());
    for (size_t i = 0; i < _configurator.getSensorNeuronCount(); ++i)
    {
        INeuron* n = new SensorNeuron(_configurator);
        _sensorNeurons.push_back(n);
    }

    // create middle neurons
    _neurons.reserve(_configurator.getMiddleNeuronCount());
    for (size_t i = 0; i < _configurator.getMiddleNeuronCount(); ++i)
    {
        INeuron* n = new Neuron(_configurator);
        _neurons.push_back(n);
    }

    // create out neurons
    _outNeurons.reserve(_configurator.getOutNeuronCount());
    for (size_t i = 0; i < _configurator.getOutNeuronCount(); ++i)
    {
        INeuron* n = new OutNeuron(_configurator);
        _outNeurons.push_back(n);
    }

    static std::default_random_engine randomGenerator;
    static std::uniform_real_distribution<double> weightDistribution(0.0, 1.0);
    static std::uniform_int_distribution<size_t> middleNeuronsDistribution(0, _configurator.getMiddleNeuronCount() - 1);

    // create sensor synapses
    for (size_t i = 0; i < _configurator.getSensorNeuronCount(); ++i)
    {
        size_t to = middleNeuronsDistribution(randomGenerator);
        double weight = 1.0;
        _sensorNeurons[i]->setNewSynapse(Synapse(_neurons[to], weight));
    }

    // create middle synapses
    for (size_t i = 0; i < _configurator.getMiddleSynapseCount(); ++i)
    {
        size_t from = middleNeuronsDistribution(randomGenerator);
        size_t to = middleNeuronsDistribution(randomGenerator);
        double weight = weightDistribution(randomGenerator);
        _neurons[from]->setNewSynapse(Synapse(_neurons[to], weight));
    }

    // create out synapses
    for (size_t outNeuronIndex = 0; outNeuronIndex < _configurator.getOutNeuronCount(); ++outNeuronIndex)
    {
        for (size_t synapseIndex = 0; synapseIndex < _configurator.getOutSynapseCount(); ++synapseIndex)
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

