// neuron_start.cpp : Defines the entry point for the console application.
//

#include "Config.h"
#include "NeuronPool.h"


int main(int argc, char* argv[])
{
    Config config;
    NeuronPool neuronPool(config);
    neuronPool.construct();
}

