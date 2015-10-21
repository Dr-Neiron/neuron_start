#pragma once
#include "NeuronPool.h"
#include "OutNeuron.h"
#include <memory>

class Environment
{
public:
    Environment(const Config& config);
    void setPool(std::shared_ptr<NeuronPool> neuronPool);
    void startLearning();
    void test();
    virtual ~Environment();

private:
    bool _isResultCorrect() const;

    std::shared_ptr<NeuronPool> _neuronPool;
    const Config& _config;
};

