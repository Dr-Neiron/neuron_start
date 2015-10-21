#pragma once
#include "Config.h"

class INeuron;

class Synapse
{
public:
    Synapse(INeuron* neuron, double weight) :
        neuron(neuron),
        weight(weight)
    {
    }

    INeuron* neuron;
    double weight;
};

class INeuron
{
public:
    explicit INeuron(const Config& config):
        _config(config)
    {
    };

    virtual void process() = 0;
    virtual void addEnergy(double addition) = 0;
    virtual bool isActive() const = 0;
    virtual void setNewSynapse(const Synapse& newSynapse) = 0;
    virtual void lockSynapseWeights(bool isLocked) = 0;

    virtual ~INeuron()
    {
    };


    INeuron() = delete;
    INeuron(const INeuron& other) = delete;
    INeuron(INeuron&& other) = delete;
    INeuron& operator=(const INeuron& other) = delete;
    INeuron& operator=(INeuron&& other) = delete;

protected:
    const Config& _config;
};
