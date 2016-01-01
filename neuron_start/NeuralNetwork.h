#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <QObject>
#include <memory>

class Environment;
class Config;
class NeuronPool;

class NeuralNetwork : public QObject
{
    Q_OBJECT
public:
    explicit NeuralNetwork(QObject *parent = 0);
    void constructDefault(std::shared_ptr<Config> config = nullptr);
    ~NeuralNetwork();

signals:

public slots:

private:
    std::unique_ptr<Environment>    _env;
    std::shared_ptr<Config>         _config;
    std::shared_ptr<NeuronPool>     _pool;
};

#endif // NEURALNETWORK_H
