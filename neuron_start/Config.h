#pragma once
class Config
{
public:
    Config();
    double getThreshold() const;
    double getIncreaseWeightAmount() const;
    double getDecreaseWeightAmount() const;
    size_t getMiddleSynapseCount() const;
    size_t getOutSynapseCount() const;
    size_t getMiddleNeuronCount() const;
    size_t getSensorNeuronCount() const;
    size_t getOutNeuronCount() const;

private:
    double _threshold;
    double _increaseWeightAmount;
    double _decreaseWeightAmount;
    size_t _middleSynapseCount;
    size_t _outSynapseCount;
    size_t _middleNeuronCount;
    size_t _sensorNeuronCount;
    size_t _outNeuronCount;
};
