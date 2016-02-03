#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Config.h"
#include "NeuronPool.h"
#include "Environment.h"
#include "networksettings.h"
#include "NeuralNetwork.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _config(std::make_shared<Config>()),
    _network(nullptr)
{
    ui->setupUi(this);
    //_network.reset(new NeuralNetwork());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_run_pushButton_clicked()
{
    _config->printConfig();

    auto neuronPool = std::make_shared<NeuronPool>(_config);
    neuronPool->construct();

    Environment env(_config);
    env.setPool(neuronPool);

    if (env.learn())
    {
        env.test();
    }
    else
    {
        _config->log() << __FUNCTION__ << ": learning failed. \n";
    }

}

void MainWindow::on_networkConfig_pushButton_clicked()
{
    NetworkSettings settings;
    settings.exec();
}
