#pragma once
class Config
{
public:
    Config();
    double getThreshold() const;
    double getIncreaseWeightAmount() const;
    double getDecreaseWeightAmount() const;
    size_t getSynapseCount() const;
    size_t getNeuronCount() const;

private:
    double _threshold;
    double _increaseWeightAmount;
    double _decreaseWeightAmount;
    size_t _synapseCount;
    size_t _neuronCount;
};

