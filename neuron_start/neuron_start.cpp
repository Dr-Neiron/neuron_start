// neuron_start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
    uint64_t neuronCount = 1000;
    uint64_t synapseCoun = 5000;

    std::vector<std::shared_ptr<INeuron>> _neurons;

    for (uint64_t i = 0; i < neuronCount; ++i)
    {
        _neurons.push_back(std::static_pointer_cast<INeuron>(std::make_shared<Neuron>()));
    }

    static std::default_random_engine generator;
    static std::uniform_int_distribution<uint64_t> distribution(0, neuronCount - 1);

    for (uint64_t i = 0; i < synapseCoun; ++i)
    {
        uint64_t randomNeuron1 = distribution(generator);
        uint64_t randomNeuron2 = distribution(generator);
        _neurons.at(randomNeuron1)->setNewSynapse(_neurons.at(randomNeuron2));
    }
}

