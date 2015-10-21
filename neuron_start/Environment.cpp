#include "Environment.h"


Environment::Environment(const Config& config):
    _config(config)
{
}

void Environment::setPool(std::shared_ptr<NeuronPool> neuronPool)
{
    _neuronPool = neuronPool;
}

void Environment::start()
{
    std::vector<INeuron*> sensors = _neuronPool->getSensorNeurons();
    std::vector<INeuron*> out = _neuronPool->getOutNeurons();

    do
    {
        sensors[0]->addEnergy(_config.getThreshold());
    } while (true);
}


Environment::~Environment()
{
}

bool Environment::_isResultCorrect(std::vector<INeuron*> outNeurons)
{
    bool result = true;

    if (dynamic_cast<OutNeuron*>(outNeurons[0])->wasActivated)
        result = true;

    for (auto neuron = outNeurons.begin() + 1; neuron != outNeurons.end(); ++neuron)
    {
        if (dynamic_cast<OutNeuron*>(neuron)->wasActivated)
            result = true;
    }

    return result;
}
