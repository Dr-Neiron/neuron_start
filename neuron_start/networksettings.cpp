#include "networksettings.h"
#include "ui_networksettings.h"

NetworkSettings::NetworkSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetworkSettings)
{
    ui->setupUi(this);
}

void NetworkSettings::setConfig(std::shared_ptr<Config> config)
{
    _config = config;
    ui->sensorNeuronCount_spinBox->setValue(_config->getSensorNeuronCount());
    ui->outNeuronCount_spinBox->setValue(_config->getOutNeuronCount());
    ui->middleNeuronCount_spinBox->setValue(_config->getMiddleNeuronCount());
    ui->middleSynapseCount_spinBox->setValue(_config->getMiddleSynapseCount());
    ui->outSynapseCount_spinBox->setValue(_config->getOutSynapseCount());
    ui->increaseWeightAmount_doubleSpinBox->setValue(_config->getIncreaseWeightAmount());
    ui->decreaseWeightAmount_doubleSpinBox->setValue(_config->getDecreaseWeightAmount());
    ui->threshold_doubleSpinBox->setValue(_config->getThreshold());
}

NetworkSettings::~NetworkSettings()
{
    delete ui;
}

void NetworkSettings::on_sensorNeuronCount_spinBox_valueChanged(int arg1)
{
    _config->setSensorNeuronCount(arg1);
}

void NetworkSettings::on_outNeuronCount_spinBox_valueChanged(int arg1)
{
    _config->setOutNeuronCount(arg1);
}

void NetworkSettings::on_middleNeuronCount_spinBox_valueChanged(int arg1)
{
    _config->setMiddleNeuronCount(arg1);
}

void NetworkSettings::on_middleSynapseCount_spinBox_valueChanged(int arg1)
{
    _config->setMiddleSynapseCount(arg1);
}

void NetworkSettings::on_outSynapseCount_spinBox_valueChanged(int arg1)
{
    _config->setOutSynapseCount(arg1);
}


void NetworkSettings::on_increaseWeightAmount_doubleSpinBox_valueChanged(double arg1)
{
    _config->setIncreaseWeightAmount(arg1);
}

void NetworkSettings::on_decreaseWeightAmount_doubleSpinBox_valueChanged(double arg1)
{
    _config->setDecreaseWeightAmount(arg1);
}

void NetworkSettings::on_threshold_doubleSpinBox_valueChanged(double arg1)
{
    _config->setThreshold(arg1);
}

void NetworkSettings::on_learnLimit_spinBox_valueChanged(int arg1)
{
    _config->setLearnLimit(arg1);
}
