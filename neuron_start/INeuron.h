#pragma once
class INeuron
{
public:
    INeuron();
    virtual void process() = 0;
    virtual void addEnergy(double addition) = 0;
    virtual ~INeuron();
};

