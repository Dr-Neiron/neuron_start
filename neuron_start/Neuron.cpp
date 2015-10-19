#include "Neuron.h"

Neuron::Neuron(const Config &configurator):
INeuron(configurator),
_currentEnergy(0),
_weightSum(0)
{
}

Neuron::~Neuron()
{
}

void Neuron::addEnergy(double addition)
{
    _currentEnergy += addition;
}

void Neuron::process()
{
    if (!isActive()) return;

    for (auto synapse = _synapses.begin(); synapse != _synapses.end(); ++synapse)
    {
        bool needIncreaseWeight = synapse->neuron->isActive();
        synapse->neuron->addEnergy(synapse->weight / _weightSum * _currentEnergy);
        if (needIncreaseWeight)
            synapse->weight += synapse->weight * _config.getIncreaseWeightAmount();
        else
            synapse->weight -= synapse->weight * _config.getDecreaseWeightAmount();
    }

    _currentEnergy = 0;
}

bool Neuron::isActive() const
{
    return _currentEnergy >= _config.getThreshold();
}

void Neuron::setNewSynapse(const Synapse& newSynapse)
{
    _synapses.push_back(newSynapse);
    _weightSum += newSynapse.weight;
}


