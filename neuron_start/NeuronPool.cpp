#include "NeuronPool.h"
#include <cstdlib>
#include <ctime>
#include "Neuron.h"

NeuronPool::NeuronPool(const Config & configurator) :
_configurator(configurator),
_size(0)
{
}

NeuronPool::~NeuronPool()
{
    if (_neurons.size() != 0)
    {
        for (size_t i = 0; i < _neurons.size(); ++i)
            delete _neurons[i];
        _neurons.clear();
    }
}

void NeuronPool::construct()
{
    _neurons.reserve(_configurator.getNeuronCount());

    // create neurons
    for (size_t i = 0; i < _configurator.getNeuronCount(); ++i)
    {
        INeuron* n = new Neuron(_configurator);
        _neurons.push_back(n);
    }


    // create synapses
    srand(time(NULL));
    for (size_t i = 0; i < _configurator.getSynapseCount(); ++i)
    {
        size_t from = rand() % _configurator.getNeuronCount() + 1;
        size_t to = rand() % _configurator.getNeuronCount() + 1;
        double weight = rand() / RAND_MAX;
        _neurons[from]->setNewSynapse(Synapse(_neurons[to], weight));

    }
}

void NeuronPool::process()
{
    for (size_t i = 0; i < _neurons.size(); ++i)
        _neurons[i]->process();
}

