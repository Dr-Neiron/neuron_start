#pragma once
#include "INeuron.h"
#include "Akson.h"
#include <memory>

class Neuron :
    public INeuron
{
public:
    virtual void process() override;
    virtual void addEnergy(double addition) override;
    Neuron();
    virtual ~Neuron();
private:
    std::shared_ptr<Akson> _akson;
};

