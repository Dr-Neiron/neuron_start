#include "stdafx.h"
#include "Akson.h"


Akson::Akson(std::shared_ptr<INeuron> parent):
_currentEnergy(0),
_parent(parent)
{
}

void Akson::setNewSynapse(std::shared_ptr<INeuron> newNeuron, double weight)
{
    _aksonSynapces.push_back(std::make_pair(newNeuron, weight));
}

void Akson::process()
{
    if (_currentEnergy != 0)
    {
        for (auto synapse : _aksonSynapces)
        {
            synapse.first->addEnergy(synapse.second * _currentEnergy);
        }
        _currentEnergy = 0;
    }
}

Akson::~Akson()
{
}
