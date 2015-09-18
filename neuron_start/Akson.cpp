#include "stdafx.h"
#include "Akson.h"


Akson::Akson(INeuron* parent):
_parent(parent)
{
}

void Akson::setNewSynapse(std::shared_ptr<INeuron> newNeuron, double weight)
{
    _aksonSynapces.push_back(std::make_pair(newNeuron, weight));
}

void Akson::processImpulse()
{
    for (auto synapse : _aksonSynapces)
    {
        synapse.first->addEnergy(synapse.second);
    }
}

Akson::~Akson()
{
}
