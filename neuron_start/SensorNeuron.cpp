#include "SensorNeuron.h"
#include <stdexcept>


SensorNeuron::SensorNeuron(std::shared_ptr<const Config> config):
    Neuron(config)
{
}

SensorNeuron::~SensorNeuron()
{
}

void SensorNeuron::setNewSynapse(const Synapse& newSynapse)
{
    if (_synapses.size() != 0)
        throw std::logic_error("Sensor neuron can have only 1 synapse.");
    Neuron::setNewSynapse(newSynapse);
}
