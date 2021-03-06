#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this ->resize(1000, 650);
    // Text string encryption algorithm Widget
    str_w = new string_algorithm();

    // The greatest common factor and least common multiple algorithm window
    num_w = new num_algorithm();


    t = new QLabel("《算法设计与分析》\n     实验平台", this);
    t->setGeometry(0,20,this->width(), this->height());
    QFont font;
    font.setPointSize(60);
    t->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_string_algorithm_triggered(bool ok)
{
    str_w->show();
}

void MainWindow::on_actionlinasdg_triggered()
{
    num_w->show();
}
