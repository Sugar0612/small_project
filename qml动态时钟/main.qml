import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 740;
    height: 680;
    title: qsTr("clock project")
    Canvas {
        id: painter
        anchors.fill: parent
        width: 400;
        height: 300;

        onPaint: {
            var pa = getContext("2d");
            drawclock(pa);

            var date = new Date();
            var hours = date.getHours();
            var min = date.getMinutes();
            var seconds = date.getSeconds();

            drawHours(hours % 12, min, pa);
            drawMinutes(min, pa);
            drawSeconds(seconds, pa);


        }
    }

    function drawSeconds(second, pa) {
        pa.save();
        pa.beginPath();
        pa.lineCap = "round"; // 圆角

        pa.translate(width / 2, height / 2);
        pa.lineWidth = 3;
        pa.strokeStyle = "red";

        var angle1 = ((-6 * second) * (1 / 57.2957795));
        var b_x = 30 * Math.sin(angle1), b_y = 30 * Math.cos(angle1);
        var e_x = 150 * Math.sin(angle1), e_y = 150 * Math.cos(angle1);

        pa.moveTo(b_x, b_y);
        pa.lineTo(-e_x, -e_y);
        pa.stroke(); // 填充
        pa.restore();
    }

    function drawMinutes(min, pa) {
        pa.save();
        pa.beginPath();
        pa.lineCap = "round";

        pa.translate(width / 2, height / 2);
        pa.lineWidth = 3;
        pa.strokeStyle = "black";

        var angle2 = ((-6 * min) * (1 / 57.2957795));
        var b_x = 30 * Math.sin(angle2), b_y = 30 * Math.cos(angle2);
        var e_x = 150 * Math.sin(angle2), e_y = 150 * Math.cos(angle2);

        pa.moveTo(b_x, b_y);
        pa.lineTo(-e_x, -e_y);
        pa.stroke(); // 填充
        pa.restore();
    }


    function drawHours(hours, min, pa) {  // 利用 min 实现时针逐渐靠近下一个小时 而不是直接跳转
        pa.save();
        pa.beginPath();
        pa.lineCap = "round";

        pa.translate(width / 2, height / 2);
        pa.lineWidth = 3;
        pa.strokeStyle = "black";

        var angle_increament = (min / 2) * 1 / 57.2957795; // 角度增量
        var angle3 = -1 * (hours * 30 * 1 / 57.2957795) + angle_increament;

        var b_x = 30 * Math.sin(angle3), b_y = 30 * Math.cos(angle3);
        var e_x = 100 * Math.sin(angle3), e_y = 100 * Math.cos(angle3);

        pa.moveTo(b_x, b_y);
        pa.lineTo(-e_x, -e_y);
        pa.stroke(); // 填充
        pa.restore();


    }


    //绘制钟表
    function drawclock(pa) {
        var r = 200;
        pa.strokeStyle = "black";

        pa.save();
        pa.beginPath();
        pa.translate(width / 2, height / 2); // 确定圆心
        pa.clearRect(-r,-r,r*2,r*2); // 确定圆心后 清除 x = -r; y = -r; width = 2r; height = 2r的矩形 重绘
        pa.lineWidth = 5;
        pa.arc(0, 0, r - 5, 0, Math.PI * 2, false); // 画圆
        pa.stroke();

        // 1度 等于 0.0175
        var num = [12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11];
        pa.font = "12px 幼圆";
        for(var i = 0; i < 12; ++i) {
            var angle = ((i * 30) * (1 / 57.2957795)); // 角度
            var x = (r - 30) * Math.sin(angle);
            var y = (r - 30) * Math.cos(angle) * -1;
            pa.fillText(num[i], x, y);  // 绘制 钟表的数字
        }


        for(var i = 0; i < 60; ++i) {
            pa.lineWidth = 2;

            var buf = 0;
            if(i % 5 == 0) buf = 6;
            var _angle = ((i * 6) * (1 / 57.2957795)); // 角度

            var b_x = (r - 5) * Math.sin(_angle);
            var b_y = (r - 5) * Math.cos(_angle) * -1;
            var e_x = b_x - ((10 + buf) * Math.sin(_angle));
            var e_y = b_y + ((10 + buf) * Math.cos(_angle));


            // 划线
            pa.moveTo(b_x, b_y);
            pa.lineTo(e_x, e_y);
            pa.stroke();
        }
        pa.restore();
    }

    Timer {
        interval: 1000;
        running: true; // start
        repeat: true; // 是否重复
        onTriggered: {
            painter.requestPaint();
        }
    }
}
