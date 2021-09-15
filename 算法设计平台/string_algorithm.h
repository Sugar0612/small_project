#ifndef STRING_ALGORITHMG_H
#define STRING_ALGORITHMG_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QPushButton>

class string_algorithm : public QWidget
{
    Q_OBJECT
public:
    explicit string_algorithm(QWidget *parent = nullptr);
    QString problem = "在数据传输过程中,为了提高传输安全性,传输的字符串可以用事先准备的编码表进行加密操作,各个字符对应的编码M表如下所示. \n"
                      "a b c d e f g h i j k l m n o p q r s t u v w x y z \n"
                      "p j w c b q o t m k h x l u s d a y e r z i v f n g \n"
                      "例一: \n"
                      "输入: hello \n"
                      "输出: tbxxs";

    QString word = "abcdefghijklmnopqrstuvwxyz";
    QString _word = "pjwcbqotmkhxlusdayerzivfng";
    QLineEdit *cin;
    QTextEdit *pro, *ans;
    QLabel *l_pro, *l_ans;
    QPushButton *ok;

    void solution();
signals:

};

#endif // STRING_ALGORITHMG_H
