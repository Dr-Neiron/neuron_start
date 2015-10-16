#include "Neuron.h"

Neuron::Neuron(const Config &configurator):
_configurator(configurator),
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

    for (std::vector<Synapse>::iterator synapse = _synapses.begin(); synapse != _synapses.end(); ++synapse)
    {
        bool needIncreaseWeight = synapse->neuron->isActive();
        synapse->neuron->addEnergy(synapse->weight / _weightSum * _currentEnergy);
        if (needIncreaseWeight)
            synapse->weight += synapse->weight * _configurator.getIncreaseWeightAmount();
        else
            synapse->weight -= synapse->weight * _configurator.getDecreaseWeightAmount();
    }

    _currentEnergy = 0;
}

bool Neuron::isActive() const
{
    return _currentEnergy >= _configurator.getThreshold();
}

void Neuron::setNewSynapse(const Synapse& newSynapse)
{
    _synapses.push_back(newSynapse);
    _weightSum += newSynapse.weight;
}


