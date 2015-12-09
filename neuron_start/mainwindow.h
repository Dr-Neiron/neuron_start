#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

namespace Ui {
class MainWindow;
}

class Config;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_run_pushButton_clicked();
    void on_networkConfig_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Config> _config;
};

#endif // MAINWINDOW_H
