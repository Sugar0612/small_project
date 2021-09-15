#include "string_algorithm.h"
#include <QMap>

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
    ok = new QPushButton("commit" ,this);
    ok->resize(50, 30);
    ok->move(330, 140);

    // ok cilcked
    connect(ok, &QPushButton::clicked, this, &string_algorithm::solution);
}

void string_algorithm::solution() {
    QString pro = this->cin->text();

    QMap<QChar, QChar> dict;
    for(int i = 0; i < word.size(); ++i) {
        QChar key = word[i], value = _word[i];
        dict[key] = value;
    }

    QString ans = "";
    for(auto c: pro) {
        char w = c.toLatin1();
        if(w - 'a' < 0 || w - 'a' > 25) {
            this->ans->setText("无效输入");
            return;
        }
        ans += dict[c];
    }

    this->ans->setText(ans);
}

