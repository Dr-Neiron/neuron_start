// neuron_start.cpp : Defines the entry point for the console application.
//

#include "Config.h"
#include "NeuronPool.h"
#include "Environment.h"
#include <memory>


int main(int argc, char* argv[])
{
    Config config;
    config.printConfig();

    auto neuronPool = std::make_shared<NeuronPool>(config);
    neuronPool->construct();

    Environment env(config);
    env.setPool(neuronPool);

    if (env.learn())
    {
        env.test();
    }
    else
    {
        config.log() << __FUNCTIONW__ << ": learning failed. \n";
        return -1;
    }

    return 0;
}

