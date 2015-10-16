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

private:
    size_t _size;
    std::vector<INeuron*> _neurons;
    const Config& _configurator;
};

