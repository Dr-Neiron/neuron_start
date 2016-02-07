#include "NeuronPool.h"
#include "Neuron.h"
#include "SensorNeuron.h"
#include "OutNeuron.h"
#include <random>
#include <stdexcept>

NeuronPool::NeuronPool(std::shared_ptr<const Config> config) :
    _size(0),
    _config(config)
{
}

NeuronPool::~NeuronPool()
{
}

void NeuronPool::construct()
{
    _config->log() << __FUNCTION__ << ": Constructing neuron pool.\n";

    // create sensor neurons
    _sensorNeurons.reserve(_config->getSensorNeuronCount());
    for (int32_t i = 0; i < _config->getSensorNeuronCount(); ++i)
    {
        _sensorNeurons.push_back(std::unique_ptr<INeuron>(new SensorNeuron(_config)));
    }

    // create middle neurons
    _neurons.reserve(_config->getMiddleNeuronCount());
    for (int32_t i = 0; i < _config->getMiddleNeuronCount(); ++i)
    {
        _neurons.push_back(std::unique_ptr<INeuron>(new Neuron(_config)));
    }

    // create out neurons
    _outNeurons.reserve(_config->getOutNeuronCount());
    for (int32_t i = 0; i < _config->getOutNeuronCount(); ++i)
    {
        _outNeurons.push_back(std::unique_ptr<INeuron>(new OutNeuron(_config)));
    }

    static std::default_random_engine randomGenerator;
    static std::uniform_real_distribution<double> weightDistribution(0.0, 1.0);
    static std::uniform_int_distribution<size_t> middleNeuronsDistribution(0, _config->getMiddleNeuronCount() - 1);

    // create sensor synapses
    for (int32_t i = 0; i < _config->getSensorNeuronCount(); ++i)
    {
        size_t to = middleNeuronsDistribution(randomGenerator);
        double weight = 1.0;
        _sensorNeurons[i]->setNewSynapse(Synapse(_neurons[to].get(), weight));
    }

    // create middle synapses
    for (int32_t i = 0; i < _config->getMiddleSynapseCount(); ++i)
    {
        size_t from = middleNeuronsDistribution(randomGenerator);
        size_t to = middleNeuronsDistribution(randomGenerator);
        double weight = weightDistribution(randomGenerator);
        _neurons[from]->setNewSynapse(Synapse(_neurons[to].get(), weight));
    }

    // create out synapses
    for (int32_t outNeuronIndex = 0; outNeuronIndex < _config->getOutNeuronCount(); ++outNeuronIndex)
    {
        for (int32_t synapseIndex = 0; synapseIndex < _config->getOutSynapseCount(); ++synapseIndex)
        {
            size_t from = middleNeuronsDistribution(randomGenerator);
            double weight = weightDistribution(randomGenerator);
            _neurons[from]->setNewSynapse(Synapse(_outNeurons[outNeuronIndex].get(), weight));
        }
    }
}

void NeuronPool::process()
{
    for (auto&& neuron:_sensorNeurons)
        neuron->process();

    for (auto&& neuron:_neurons)
        neuron->process();

    for (auto&& neuron:_outNeurons)
        neuron->process();
}

void NeuronPool::lockSynapseWeights(bool isLocked)
{
    for (auto&& neuron : _neurons)
        neuron->lockSynapseWeights(isLocked);
}

const std::vector<std::unique_ptr<INeuron>>& NeuronPool::getSensorNeurons() const
{
    return _sensorNeurons;
}

const std::vector<std::unique_ptr<INeuron> > &NeuronPool::getOutNeurons() const
{
    return _outNeurons;
}

void NeuronPool::dumpNetwork(std::ofstream* out) const
{
    fileName.clear();   // remove compiler warning
    throw std::runtime_error("Not implemented");
}
