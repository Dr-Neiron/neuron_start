#pragma once

class INeuron;

class Synapse
{
public:
    Synapse(INeuron* neuron, double weight) :
        neuron(neuron),
        weight(weight)
    {}

    INeuron* neuron;
    double weight;
};

class INeuron
{
public:
    INeuron(){};
    virtual void process() = 0;
    virtual void addEnergy(double addition) = 0;
    virtual bool isActive() const = 0;
    virtual void setNewSynapse(const Synapse& newSynapse) = 0;
    virtual ~INeuron(){};

};

