#pragma once
#include "NeuronPool.h"
#include <memory>

class Environment
{
public:
    Environment();
    void setPool(std::shared_ptr<NeuronPool> neuronPool);
    void start();
    virtual ~Environment();

private:
    std::shared_ptr<NeuronPool> _pool;
};

