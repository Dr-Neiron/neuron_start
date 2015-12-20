#include "Environment.h"


Environment::Environment(const Config& config):
    _config(config)
{
}

void Environment::setPool(std::shared_ptr<NeuronPool> neuronPool)
{
    _neuronPool = neuronPool;
}

bool Environment::learn()
{
    const std::vector<std::unique_ptr<INeuron>>& sensors = _neuronPool->getSensorNeurons();
    size_t counter = 0;
    _config.log() << __FUNCTION__ << ": starting learning...\n";
    do
    {
        sensors[0]->addEnergy(_config.getThreshold());
        _neuronPool->process();
        counter++;
        if (counter >= _config.getLearnLimit())
        {
            _config.log() << __FUNCTION__ << L": learning stopped by counter limit. counter=" << counter << "\n";
            return false;
        }
    } while (!_isResultCorrect());
    _config.log() << __FUNCTION__ << ": learning finished. counter=" << counter << "\n";
    return true;
}

void Environment::test()
{
    //std::vector<INeuron*> sensors = _neuronPool->getSensorNeurons();
    _config.log() << __FUNCTION__ << ": starting testing...\n";
}

Environment::~Environment()
{
}

bool Environment::_isResultCorrect() const
{
    const std::vector<std::unique_ptr<INeuron>>& outNeurons = _neuronPool->getOutNeurons();

    // for now fisrt checked for 1, other for 0
    if (!dynamic_cast<OutNeuron*>(outNeurons[0].get())->wasActivated())
        return false;

    for (size_t i = 1; i < outNeurons.size(); ++i)
    {
        if (dynamic_cast<OutNeuron*>(outNeurons[i].get())->wasActivated())
            return false;
    }

    return true;
}
