#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include "string_algorithm.h"
#include "num_algorithm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLabel *t = nullptr;
    string_algorithm *str_w = nullptr;
    num_algorithm *num_w = nullptr;

private slots:
    void on_string_algorithm_triggered(bool ok); // Text string encryption algorithm

    void on_actionlinasdg_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
