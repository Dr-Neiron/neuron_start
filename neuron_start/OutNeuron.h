#pragma once
#include "Neuron.h"

class OutNeuron :
    public Neuron
{
public:
    explicit OutNeuron(const Config& config);
    virtual ~OutNeuron();

    virtual void process() override;
    virtual void setNewSynapse(const Synapse& newSynapse) override;

    bool wasActivated() const;

private:
    bool _wasActivated;
};
