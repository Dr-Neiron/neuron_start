#pragma once
#include "INeuron.h"
#include "Akson.h"
#include <memory>

class Neuron :
    public INeuron
{
public:
    Neuron();
    virtual ~Neuron();

    virtual void process() override;
    virtual void addEnergy(double addition) override;
    virtual bool isActive() const override;
    virtual void setNewSynapse(std::shared_ptr<INeuron> otherNeuron) override;

private:
    Neuron(const Neuron& other) = delete;
    Neuron(Neuron&& other) = delete;
    Neuron& operator=(const Neuron& other) = delete;
    Neuron& operator=(Neuron&& other) = delete;

    std::unique_ptr<Akson> _akson;
    double _currentEnergy;
};

