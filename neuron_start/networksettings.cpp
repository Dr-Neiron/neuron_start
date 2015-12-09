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
    ui->threshold_doubleSpinBox->setValue(_config->getThreshold());
    ui->increaseWeightAmount_doubleSpinBox->setValue(_config->getIncreaseWeightAmount());
    ui->middleSynapseCount_spinBox->setValue(_config->getMiddleSynapseCount());
    ui->middleSynapseCount_spinBox->setValue(_config->getMiddleSynapseCount());
    ui->middleSynapseCount_spinBox->setValue(_config->getMiddleSynapseCount());
    ui->middleSynapseCount_spinBox->setValue(_config->getMiddleSynapseCount());
    ui->middleSynapseCount_spinBox->setValue(_config->getMiddleSynapseCount());
    ui->middleSynapseCount_spinBox->setValue(_config->getMiddleSynapseCount());
}

NetworkSettings::~NetworkSettings()
{
    delete ui;
}
