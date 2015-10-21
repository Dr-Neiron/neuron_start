#pragma once
#include <vector>
#include "Config.h"
#include "INeuron.h"

class NeuronPool
{
public:
    NeuronPool(const Config& configurator);
    ~NeuronPool();
    void construct();
    void process();
    void lockSynapseWeights(bool isLocked);
    std::vector<INeuron*> getSensorNeurons() const;
    std::vector<INeuron*> getOutNeurons() const;

private:
    size_t _size;
    std::vector<INeuron*> _neurons;
    std::vector<INeuron*> _sensorNeurons;
    std::vector<INeuron*> _outNeurons;
    const Config& _config;
};
