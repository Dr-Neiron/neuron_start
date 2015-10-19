#include "Config.h"


Config::Config():
    _threshold(0.5),
    _increaseWeightAmount(0.1),
    _decreaseWeightAmount(0.05),
    _middleSynapseCount(10),
    _outSynapseCount(4),
    _middleNeuronCount(5),
    _sensorNeuronCount(2),
    _outNeuronCount(2)
{
}

double Config::getThreshold() const
{
    return _threshold;
}

double Config::getIncreaseWeightAmount() const
{
    return _increaseWeightAmount;
}

double Config::getDecreaseWeightAmount() const
{
    return _decreaseWeightAmount;
}

size_t Config::getMiddleSynapseCount() const
{
    return _middleSynapseCount;
}

size_t Config::getOutSynapseCount() const
{
    return _outSynapseCount;
}

size_t Config::getMiddleNeuronCount() const
{
    return _middleNeuronCount;
}

size_t Config::getSensorNeuronCount() const
{
    return _sensorNeuronCount;
}

size_t Config::getOutNeuronCount() const
{
    return _outNeuronCount;
}
