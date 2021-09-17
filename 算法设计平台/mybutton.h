#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    int active;
    //explicit myButton(QWidget *parent = nullptr);
    myButton(int act);

signals:
    void my_clicked(int act);
};

#endif // MYBUTTON_H
