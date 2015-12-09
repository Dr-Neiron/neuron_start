#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Config.h"
#include "NeuronPool.h"
#include "Environment.h"
#include "networksettings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_run_pushButton_clicked()
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
            config.log() << __FUNCTION__ << ": learning failed. \n";
        }

}

void MainWindow::on_networkConfig_pushButton_clicked()
{
    NetworkSettings settings;
    settings.exec();
}
