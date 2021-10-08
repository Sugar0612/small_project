#include "num_algorithm.h"
#include <QDebug>
#include <algorithm>
#include <iostream>
using namespace::std;

num_algorithm::num_algorithm(QWidget *parent) : QWidget(parent)
{
    this ->setFixedSize(400, 300);

    cin1_l = new QLabel("a: ",this);
    cin1_l->setGeometry(80, 25, 50, 15);

    cin2_l = new QLabel("b: ", this);
    cin2_l->setGeometry(80, 65, 50, 15);

    ans1_l = new QLabel("最大公约数: ",this);
    ans1_l->setGeometry(30, 220, 80, 20);

    ans2_l = new QLabel("最小公倍数: ", this);
    ans2_l->setGeometry(30, 260, 80, 20);

    fun1 = new QPushButton("短除法",this);
    fun1->setGeometry(100, 100, 100, 30);

    fun2 = new QPushButton("辗转相除法", this);
    fun2->setGeometry(100, 140, 100, 30);

    fun3 = new QPushButton("更相减损法", this);
    fun3->setGeometry(100, 180, 100, 30);

    cout1 = new QLineEdit(this);
    cout1->setGeometry(100, 20, 100, 30);

    cout2 = new QLineEdit(this);
    cout2->setGeometry(100, 60, 100, 30);

    ans1 = new QTextEdit(this);
    ans1->setGeometry(100, 220, 100, 30);
    ans1->setReadOnly(true);

    ans2 = new QTextEdit(this);
    ans2->setGeometry(100, 260, 100, 30);
    ans2->setReadOnly(true);

    connect(fun1, &QPushButton::clicked, this, &num_algorithm::Short_division);
    connect(fun2, &QPushButton::clicked, this, &num_algorithm::Toss_and_divide);
    connect(fun3, &QPushButton::clicked, this, &num_algorithm::More_subtraction);
}

bool num_algorithm::is_empty() {
    QString s_a = cout1->text();
    QString s_b = cout2->text();
    if(s_a.size() == 0 || s_b.size() == 0 || (s_a == "0" && s_b == "0")) {
        QString res = "无效输入!";
        ans1->setText(res);
        ans2->setText(res);
        return false;
    }
    return true;
}


void num_algorithm::Short_division() {
    if(!is_empty()) return;

    a = cout1->text().toInt();
    b = cout2->text().toInt();

    int i = 2, max = 1, min = 1;
    QVector<int> buf;
    while(i <= a && i <= b) {
        if(a % i == 0 && b % i == 0) {
            buf.push_back(i);
            a /= i;
            b /= i;
            continue;
        }
        i++;
    }
    for(int val: buf) max *= val;
    min = max * a * b;
    QString s_max = QString::number(max);
    QString s_min = QString::number(min);

    ans1->setText(s_max);
    ans2->setText(s_min);
}

void num_algorithm::Toss_and_divide() {
    if(!is_empty()) return;

    a = cout1->text().toInt();
    b = cout2->text().toInt();
    int _a = a, _b = b;

    a = max(_a, _b);
    b = min(_a, _b);

    _a = a;
    _b = b;
    int temp = 0;
    while(a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    QString s_max = QString::number(temp);
    QString s_min = QString::number(_a * _b / temp);

    ans1->setText(s_max);
    ans2->setText(s_min);
}

void num_algorithm::More_subtraction() {
    if(!is_empty()) return;

    a = cout1->text().toInt();
    b = cout2->text().toInt();

    int _a = a, _b = b;

    a = max(_a, _b);
    b = min(_a, _b);

    _a = a;
    _b = b;
    int temp = 0;
    while(a - b > 0) {
        temp = a - b;
        a = max(b, temp);
        b = min(b, temp);
    }
    QString s_max = QString::number(temp);
    QString s_min = QString::number(_a * _b / temp);

    ans1->setText(s_max);
    ans2->setText(s_min);
}
