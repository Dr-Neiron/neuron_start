#pragma once
#include "NeuronPool.h"
#include "OutNeuron.h"
#include <memory>

class Environment
{
public:
    Environment(const Config& config);
    void setPool(std::shared_ptr<NeuronPool> neuronPool);
    void start();
    virtual ~Environment();

private:
    bool _isResultCorrect(std::vector<INeuron*> outNeurons);

    std::shared_ptr<NeuronPool> _neuronPool;
    const Config& _config;
};

