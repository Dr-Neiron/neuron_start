#include "Environment.h"


Environment::Environment()
{
}

void Environment::setPool(std::shared_ptr<NeuronPool> neuronPool)
{
    _pool = neuronPool;
}

void Environment::start()
{
}


Environment::~Environment()
{
}
