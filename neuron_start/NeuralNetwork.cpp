#include "NeuralNetwork.h"
#include "Config.h"
#include "Environment.h"
#include "NeuronPool.h"

NeuralNetwork::NeuralNetwork(QObject *parent) :
    QObject(parent),
    _pool(nullptr),
    _config(std::make_shared<Config>()),
    _env(nullptr)
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

NeuralNetwork::~NeuralNetwork()
{

}
