#ifndef NUM_ALGORITHM_H
#define NUM_ALGORITHM_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>

class num_algorithm : public QWidget
{
    Q_OBJECT
public:
    explicit num_algorithm(QWidget *parent = nullptr);
    QPushButton *fun1, *fun2, *fun3;
    QTextEdit *ans1, *ans2;
    QLineEdit *cout1, *cout2;

    QLabel *cin1_l, *cin2_l, *ans1_l, *ans2_l;

    bool is_empty();

    void Short_division();
    void Toss_and_divide();
    void More_subtraction();


    int a, b;
signals:

};

#endif // NUM_ALGORITHM_H
