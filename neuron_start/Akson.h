#pragma once
#include <vector>
#include <memory>
#include "INeuron.h"

class Akson
{
public:
    explicit Akson(INeuron* parent);
    virtual ~Akson();

    void setNewSynapse(std::shared_ptr<INeuron> newNeuron, double weight);
    void processImpulse();

private:
    Akson() = delete;
    Akson(const Akson& other) = delete;
    Akson(Akson&& other) = delete;
    Akson& operator=(const Akson& other) = delete;
    Akson& operator=(Akson&& other) = delete;
    
    INeuron* _parent;
    std::vector<std::pair<std::shared_ptr<INeuron>, double>> _aksonSynapces;

};

