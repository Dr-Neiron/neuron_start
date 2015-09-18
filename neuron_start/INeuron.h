#pragma once
#include <memory>

class INeuron
{
public:
    INeuron(){};
    virtual void process() = 0;
    virtual void addEnergy(double addition) = 0;
    virtual bool isActive() const = 0;
    virtual void setNewSynapse(std::shared_ptr<INeuron> otherNeuron) = 0;
    virtual ~INeuron(){};

    const double BORDER_VALUE = 1.0;
};

