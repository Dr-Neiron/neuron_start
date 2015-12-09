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
    size_t getMiddleSynapseCount() const;
    size_t getOutSynapseCount() const;
    size_t getMiddleNeuronCount() const;
    size_t getSensorNeuronCount() const;
    size_t getOutNeuronCount() const;
    size_t getLearnLimit() const;

    // setters
    void setThreshold(double threshold);
    void setIncreaseWeightAmount(double increaseWeightAmount);
    void setDecreaseWeightAmount(double decreaseWeightAmount);
    void setMiddleSynapseCount(size_t middleSynapseCount);
    void setOutSynapseCount(size_t outSynapseCount);
    void setMiddleNeuronCount(size_t middleNeuronCount);
    void setSensorNeuronCount(size_t sensorNeuronCount);
    void setOutNeuronCount(size_t outNeuronCount);
    void setLearnLimit(size_t learnLimit);

    void printConfig() const;
    const Logger& log() const;

private:

    // parameters
    double _threshold;
    double _increaseWeightAmount;
    double _decreaseWeightAmount;
    size_t _middleSynapseCount;
    size_t _outSynapseCount;
    size_t _middleNeuronCount;
    size_t _sensorNeuronCount;
    size_t _outNeuronCount;
    size_t _learnLimit;

    // etc.
    Logger _logger;
};
