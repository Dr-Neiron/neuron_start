#pragma once
#include "Logger.h"

class Config
{
public:
    Config();

    // getters
    double getThreshold() const;
    double getIncreaseWeightAmount() const;
    double getDecreaseWeightAmount() const;
    int32_t getMiddleSynapseCount() const;
    int32_t getOutSynapseCount() const;
    int32_t getMiddleNeuronCount() const;
    int32_t getSensorNeuronCount() const;
    int32_t getOutNeuronCount() const;
    int32_t getLearnLimit() const;

    // setters
    void setThreshold(double threshold);
    void setIncreaseWeightAmount(double increaseWeightAmount);
    void setDecreaseWeightAmount(double decreaseWeightAmount);
    void setMiddleSynapseCount(int32_t middleSynapseCount);
    void setOutSynapseCount(int32_t outSynapseCount);
    void setMiddleNeuronCount(int32_t middleNeuronCount);
    void setSensorNeuronCount(int32_t sensorNeuronCount);
    void setOutNeuronCount(int32_t outNeuronCount);
    void setLearnLimit(int32_t learnLimit);

    void printConfig() const;
    const Logger& log() const;

private:

    // parameters
    double _threshold;
    double _increaseWeightAmount;
    double _decreaseWeightAmount;
    int32_t _middleSynapseCount;
    int32_t _outSynapseCount;
    int32_t _middleNeuronCount;
    int32_t _sensorNeuronCount;
    int32_t _outNeuronCount;
    int32_t _learnLimit;

    // etc.
    Logger _logger;
};
