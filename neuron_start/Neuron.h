#pragma once
#include "INeuron.h"
#include "Config.h"
#include <vector>

class Neuron :
    public INeuron
{
public:
    explicit Neuron(const Config& config);
    virtual ~Neuron();

    virtual void process() override;
    virtual void addEnergy(double addition) override;
    virtual bool isActive() const override;
    virtual void setNewSynapse(const Synapse& newSynapse) override;
    virtual void lockSynapseWeights(bool isLocked) override;

protected:
    double _currentEnergy;
    double _weightSum;
    std::vector<Synapse> _synapses;
    bool _isLearning;
};
