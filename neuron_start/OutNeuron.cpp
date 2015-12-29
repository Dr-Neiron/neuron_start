#include "OutNeuron.h"
#include <stdexcept>


OutNeuron::OutNeuron(std::shared_ptr<const Config> config):
    Neuron(config),
    _wasActivated(false)
{
}

OutNeuron::~OutNeuron()
{
}

void OutNeuron::process()
{
    if (_currentEnergy >= _config->getThreshold())
        _wasActivated = true;
    else
        _wasActivated = false;
}

void OutNeuron::setNewSynapse(const Synapse& newSynapse)
{
    throw std::logic_error("Out neurons can not have synapses.");
}

bool OutNeuron::wasActivated() const
{
    return _wasActivated;
}
