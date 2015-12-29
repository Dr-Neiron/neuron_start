#pragma once
#include "NeuronPool.h"
#include "OutNeuron.h"
#include <memory>

class Environment
{
public:
    explicit Environment(std::shared_ptr<const Config> config);
    void setPool(std::shared_ptr<NeuronPool> neuronPool);
    bool learn();
    void test();
    virtual ~Environment();


    Environment() = delete;
    Environment(const Environment& other) = delete;
    Environment(Environment&& other) = delete;
    Environment& operator=(const Environment& other) = delete;
    Environment& operator=(Environment&& other) = delete;

private:
    bool _isResultCorrect() const;

    std::shared_ptr<NeuronPool> _neuronPool;
    std::shared_ptr<const Config> _config;
};

