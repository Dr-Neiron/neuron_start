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
    _network.reset(new NeuralNetwork());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_run_pushButton_clicked()
{
    _network->constructDefault(_config);
}

void MainWindow::on_networkConfig_pushButton_clicked()
{
    NetworkSettings settings;
    settings.setConfig(_config);
    settings.exec();
}

void MainWindow::on_dump_pushButton_clicked()
{

}
