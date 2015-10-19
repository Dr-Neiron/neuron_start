#pragma once
#include "Neuron.h"

class SensorNeuron :
    public Neuron
{
public:
    explicit SensorNeuron(const Config& config);
    virtual ~SensorNeuron();
    virtual void setNewSynapse(const Synapse& newSynapse) override;
};
