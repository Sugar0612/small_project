#include "string_algorithm.h"
#include <QMap>
#include <QDebug>
#include <algorithm>
#include <qalgorithms.h>

string_algorithm::string_algorithm(QWidget *parent) : QWidget(parent)
{
    this ->setFixedSize(400, 300);

    // problem
    pro = new QTextEdit(this);
    pro->setFixedSize(QSize(400, 120));
    pro->setText(problem);
    pro->setReadOnly(true);

    //cin
    cin = new QLineEdit(this);
    cin ->move(120, 140);
    cin ->resize(200, 30);

    // ans
    ans = new QTextEdit(this);
    ans->move(120, 200);
    ans->resize(200, 30);
    ans->setReadOnly(true);

    // l_pro
    l_pro = new QLabel("测试用例:",this);
    l_pro->move(60, 140);
    l_pro->resize(60, 30);

    //l_ans
    l_ans = new QLabel("输出: ", this);
    l_ans->move(80, 200);
    l_ans->resize(60, 30);


    // ok
    enpt = new myButton(0);
    enpt ->setParent(this);
    enpt->setText("加密");
    enpt->setGeometry(330, 140, 60, 30);

    // dept
    dept = new myButton(1);
    dept ->setParent(this);
    dept->setText("解密");
    dept->setGeometry(330, 200, 60, 30);

    // ok cilcked
    connect(enpt, &myButton::my_clicked, this, &string_algorithm::solution_code);

    // dept cilcked
    connect(dept, &myButton::my_clicked, this, &string_algorithm::solution_code);
}

void string_algorithm::solution_code(int act) {
    if(0 == act) {  // encryption
        QString pro = this->cin->text();

        QMap<QChar, QChar> dict;
        for(int i = 0; i < word.size(); ++i) {
            QChar key = word[i], value = _word[i];
            dict[key] = value;
        }

        QString ans = "";
        for(auto c: pro) {
            char w = c.toLatin1();
            if(qFind(word.begin(), word.end(), c) == word.end()) {
                this->ans->setText("无效输入");
                return;
            }
            ans += dict[c];
        }
        this->ans->setText(ans);
    }

    else if(1 == act) {
        QString pro = this->cin->text();

        QMap<QChar, QChar> dict;
        for(int i = 0; i < _word.size(); ++i) {
            QChar key = _word[i], value = word[i];
            dict[key] = value;
        }

        QString ans = "";
        for(auto c: pro) {
            char w = c.toLatin1();
            if(qFind(_word.begin(), _word.end(), c) == _word.end()) {
                this->ans->setText("无效输入");
                return;
            }
            ans += dict[c];
        }
        this->ans->setText(ans);
    }
}
