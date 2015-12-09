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

private:
    Ui::NetworkSettings *ui;

    std::shared_ptr<Config> _config;
};

#endif // NETWORKSETTINGS_H
