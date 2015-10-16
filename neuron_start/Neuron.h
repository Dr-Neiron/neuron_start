#pragma once
#include "INeuron.h"
#include "Config.h"
#include <vector>

class Neuron :
    public INeuron
{
public:
    Neuron(const Config& config);
    virtual ~Neuron();

    virtual void process() override;
    virtual void addEnergy(double addition) override;
    virtual bool isActive() const override;
    virtual void setNewSynapse(const Synapse& newSynapse) override;

private:
    Neuron(const Neuron& other) = delete;
    Neuron(Neuron&& other) = delete;
    Neuron& operator=(const Neuron& other) = delete;
    Neuron& operator=(Neuron&& other) = delete;

    const Config& _configurator;
    double _currentEnergy;
    double _weightSum;
    std::vector<Synapse> _synapses;
};

