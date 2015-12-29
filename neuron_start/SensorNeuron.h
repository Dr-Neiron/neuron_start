#pragma once
#include "Neuron.h"

class SensorNeuron :
    public Neuron
{
public:
    explicit SensorNeuron(std::shared_ptr<const Config> config);
    virtual ~SensorNeuron();
    virtual void setNewSynapse(const Synapse& newSynapse) override;
};
