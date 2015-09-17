#pragma once
#include <vector>
#include <memory>
#include "INeuron.h"

class Akson
{
public:
    explicit Akson(std::shared_ptr<INeuron> parent);
    void setNewSynapse(std::shared_ptr<INeuron> newNeuron, double weight);
    void process();
    virtual ~Akson();
private:
    Akson();
    double _currentEnergy;
    std::shared_ptr<INeuron> _parent;
    std::vector<std::pair<std::shared_ptr<INeuron>, double>> _aksonSynapces;

};

