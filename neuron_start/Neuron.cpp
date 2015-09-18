#include "stdafx.h"
#include "Neuron.h"
#include <random>

Neuron::Neuron():
_akson(new Akson(this)),
_currentEnergy(0)
{
}


void Neuron::process()
{
    if (_currentEnergy >= BORDER_VALUE)
    {
        _akson->processImpulse();
        _currentEnergy = 0;
    }
}

void Neuron::addEnergy(double addition)
{
    _currentEnergy += addition;
}

bool Neuron::isActive() const
{
    return _currentEnergy >= BORDER_VALUE;
}

void Neuron::setNewSynapse(std::shared_ptr<INeuron> otherNeuron)
{
    static std::default_random_engine generator;
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double randomWeight = distribution(generator);
    _akson->setNewSynapse(otherNeuron, randomWeight);
}

Neuron::~Neuron()
{
}
