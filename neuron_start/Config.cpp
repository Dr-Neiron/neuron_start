#include "Config.h"


Config::Config():
    _threshold(0.5),
    _increaseWeightAmount(0.1),
    _decreaseWeightAmount(0.05),
    _middleSynapseCount(5000),
    _outSynapseCount(100),
    _middleNeuronCount(1000),
    _sensorNeuronCount(4),
    _outNeuronCount(4),
    _learnLimit(100000)
{
}

// getters
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

size_t Config::getLearnLimit() const
{
    return _learnLimit;
}

// setters
void Config::setThreshold(double threshold)
{
    _threshold = threshold;
}


void Config::setIncreaseWeightAmount(double increaseWeightAmount)
{
    _increaseWeightAmount = increaseWeightAmount;
}


void Config::setDecreaseWeightAmount(double decreaseWeightAmount)
{
    _decreaseWeightAmount = decreaseWeightAmount;
}


void Config::setMiddleSynapseCount(size_t middleSynapseCount)
{
    _middleSynapseCount = middleSynapseCount;
}


void Config::setOutSynapseCount(size_t outSynapseCount)
{
    _outSynapseCount = outSynapseCount;
}


void Config::setMiddleNeuronCount(size_t middleNeuronCount)
{
    _middleNeuronCount = middleNeuronCount;
}


void Config::setSensorNeuronCount(size_t sensorNeuronCount)
{
    _sensorNeuronCount = sensorNeuronCount;
}


void Config::setOutNeuronCount(size_t outNeuronCount)
{
    _outNeuronCount = outNeuronCount;
}


void Config::setLearnLimit(size_t learnLimit)
{
    _learnLimit = learnLimit;
}



// etc.
void Config::printConfig() const
{
    log() << "Configuration:\n";
    log() << "\tthreshold: " << _threshold << "\n";
    log() << "\tincreaseWeightAmount: " << _increaseWeightAmount << "\n";
    log() << "\tdecreaseWeightAmount: " << _decreaseWeightAmount << "\n";
    log() << "\tmiddleSynapseCount: " << _middleSynapseCount << "\n";
    log() << "\toutSynapseCount: " << _outSynapseCount << "\n";
    log() << "\tmiddleNeuronCount: " << _middleNeuronCount << "\n";
    log() << "\tsensorNeuronCount: " << _sensorNeuronCount << "\n";
    log() << "\toutNeuronCount: " << _outNeuronCount << "\n";
}

const Logger& Config::log() const
{
    return _logger;
}
