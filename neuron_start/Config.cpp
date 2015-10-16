#include "Config.h"


Config::Config():
    _threshold(0.5),
    _increaseWeightAmount(0.1),
    _decreaseWeightAmount(0.05),
    _synapseCount(10),
    _neuronCount(5)
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

size_t Config::getSynapseCount() const
{
    return _synapseCount;
}

size_t Config::getNeuronCount() const
{
    return _neuronCount;
}
