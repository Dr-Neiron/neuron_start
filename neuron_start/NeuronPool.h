#pragma once
#include <vector>
#include <memory>
#include "Config.h"
#include "INeuron.h"

class NeuronPool
{
public:
    NeuronPool(std::shared_ptr<const Config> config);
    ~NeuronPool();
    void construct();
    void process();
    void lockSynapseWeights(bool isLocked);
    const std::vector<std::unique_ptr<INeuron>>& getSensorNeurons() const;
    const std::vector<std::unique_ptr<INeuron>>& getOutNeurons() const;
    void dumpNetwork() const;


    NeuronPool() = delete;
    NeuronPool(const NeuronPool& other) = delete;
    NeuronPool(NeuronPool&& other) = delete;
    NeuronPool& operator=(const NeuronPool& other) = delete;
    NeuronPool& operator=(NeuronPool&& other) = delete;

private:
    size_t _size;
    std::vector<std::unique_ptr<INeuron>> _neurons;
    std::vector<std::unique_ptr<INeuron>> _sensorNeurons;
    std::vector<std::unique_ptr<INeuron>> _outNeurons;
    std::shared_ptr<const Config> _config;
};
