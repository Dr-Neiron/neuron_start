#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <QDialog>
#include <Config.h>
#include <memory>

namespace Ui {
class NetworkSettings;
}

class NetworkSettings : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkSettings(QWidget *parent = 0);
    void setConfig(std::shared_ptr<Config> config);
    ~NetworkSettings();

private slots:
    void on_sensorNeuronCount_spinBox_valueChanged(int arg1);

    void on_outNeuronCount_spinBox_valueChanged(int arg1);

    void on_middleNeuronCount_spinBox_valueChanged(int arg1);

    void on_middleSynapseCount_spinBox_valueChanged(int arg1);

    void on_outSynapseCount_spinBox_valueChanged(int arg1);

    void on_increaseWeightAmount_doubleSpinBox_valueChanged(double arg1);

    void on_decreaseWeightAmount_doubleSpinBox_valueChanged(double arg1);

    void on_threshold_doubleSpinBox_valueChanged(double arg1);

    void on_learnLimit_spinBox_valueChanged(int arg1);

private:
    Ui::NetworkSettings *ui;

    std::shared_ptr<Config> _config;
};

#endif // NETWORKSETTINGS_H
