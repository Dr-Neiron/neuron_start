#include "Environment.h"


Environment::Environment(const Config& config):
    _config(config)
{
}

void Environment::setPool(std::shared_ptr<NeuronPool> neuronPool)
{
    _neuronPool = neuronPool;
}

void Environment::startLearning()
{
    std::vector<INeuron*> sensors = _neuronPool->getSensorNeurons();
    size_t counter = 0;
    _config.log() << __FUNCTIONW__ << L": starting learning...\n";
    do
    {
        sensors[0]->addEnergy(_config.getThreshold());
        _neuronPool->process();
        counter++;
    } while (_isResultCorrect());
    _config.log() << __FUNCTIONW__ << L": learning finished. counter=" << counter << "\n";
}

void Environment::test()
{
    std::vector<INeuron*> sensors = _neuronPool->getSensorNeurons();
    _config.log() << __FUNCTIONW__ << L": starting testing...\n";
}

Environment::~Environment()
{
}

bool Environment::_isResultCorrect() const
{
    std::vector<INeuron*> outNeurons = _neuronPool->getOutNeurons();

    // for now fisrt checked for 1, other for 0
    if (!dynamic_cast<OutNeuron*>(outNeurons[0])->wasActivated())
        return false;

    for (size_t i = 1; i < outNeurons.size(); ++i)
    {
        if (dynamic_cast<OutNeuron*>(outNeurons[i])->wasActivated())
            return false;
    }

    return true;
}
