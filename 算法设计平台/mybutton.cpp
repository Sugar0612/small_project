#include "mybutton.h"

myButton::myButton(int act): active(act) {
    connect(this, &myButton::clicked, [=] () {
        emit my_clicked(active);
    });
}
