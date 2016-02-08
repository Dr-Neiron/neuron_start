#include "NeuralNetwork.h"
#include "Config.h"
#include "Environment.h"
#include "NeuronPool.h"

NeuralNetwork::NeuralNetwork(QObject *parent) :
    QObject(parent),
    _env(nullptr),
    _config(std::make_shared<Config>()),
    _pool(nullptr)
{

}

void NeuralNetwork::constructDefault(std::shared_ptr<Config> config)
{
    if (config)
    {
        _config = config;
    }

    _pool = std::make_shared<NeuronPool>(_config);
    _pool->construct();

    _env.reset(new Environment(_config));
    _env->setPool(_pool);
}

bool NeuralNetwork::learn()
{
    return _env->learn();
}

void NeuralNetwork::dump()
{
    _pool->dumpNetwork();
}

NeuralNetwork::~NeuralNetwork()
{

}
