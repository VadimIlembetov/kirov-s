#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //координаты оборудования
    xdev = 50;
    ydev = 200;
    //параметры мельницы
    wmc = 100;
    hmc = 200;
    scalemc = 1.5;
    wmc = wmc  * scalemc;
    hmc = hmc * scalemc;
    //параметры классификатора
    wkld = 100;
    hkld = 200;
    scalekld = 1;
    wkld = wkld  * scalekld;
    hkld = hkld * scalekld;
    //параметры циклона
    wckl = 100;
    hckl = 200;
    scaleckl = 1;
    wckl = wckl  * scaleckl;
    hckl = hckl * scaleckl;
    //параметры фильтра
    wfar = 200;
    hfar = 200;
    scalefar = 1;
    wfar = wfar  * scalefar;
    hfar = hfar * scalefar;

    //инициализация объекта таймера
    timer_cycle = new QTimer();
    //соединим сигнал таймера со слотом обновления экрана
    connect(timer_cycle,SIGNAL(timeout()),this,SLOT(cycle()));
    //запустим таймер
    timer_cycle->start(20);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cycle()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    qreal x, y, xd;

    //заливка
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    painter.setBrush(brush);

    //мельница
    x = xdev;
    y = ydev;
    painter.drawRect(x, y, wmc + 2*wmc*0.1, hmc*0.2);
    x = xdev + wmc*0.1;
    y = ydev + hmc*0.2;
    static const QPointF pointsmc[6] = {
        QPointF(x, y),
        QPointF(x + wmc, y),
        QPointF(x + wmc, y + hmc*0.6),
        QPointF(x + wmc*0.3, y + hmc*0.8),
        QPointF(x + wmc*0.3, y + hmc),
        QPointF(x, y + hmc)
    };
    painter.drawPolygon(pointsmc, 6);

    //классификатор
    xd = 250;
    x = xdev + xd;
    y = ydev;
    painter.drawRect(x, y, wkld + 2*wkld*0.1, hkld*0.2);
    x = xdev + wkld*0.1 + xd;
    y = ydev + hkld*0.2;
    static const QPointF pointskld[10] = {
        QPointF(x, y + hkld*0.25),
        QPointF(x + wkld*0.25, y + hkld*0.25),
        QPointF(x + wkld*0.25, y),
        QPointF(x + wkld*0.75, y),
        QPointF(x + wkld*0.75, y + hkld*0.25),
        QPointF(x + wkld, y + hkld*0.25),
        QPointF(x + wkld, y + hkld*0.35),
        QPointF(x + wkld*0.7, y + hkld*0.65),
        QPointF(x + wkld*0.3, y + hkld*0.65),
        QPointF(x, y + hkld*0.35)
    };
    painter.drawPolygon(pointskld, 10);
    //циклон
    xd = 450;
    x = xdev + xd;
    y = ydev;
    painter.drawRect(x, y, wckl + 2*wckl*0.1, hckl*0.2);
    x = xdev + wckl*0.1 + xd;
    y = ydev + hckl*0.2;
    static const QPointF pointsckl[14] = {
        QPointF(x, y + hckl*0.25),
        QPointF(x + wckl*0.15, y + hckl*0.25),
        QPointF(x + wckl*0.15, y),
        QPointF(x + wckl*0.4, y),
        QPointF(x + wckl*0.4, y + hckl*0.25),
        QPointF(x + wckl*0.6, y + hckl*0.25),
        QPointF(x + wckl*0.6, y),
        QPointF(x + wckl*0.85, y),
        QPointF(x + wckl*0.85, y + hckl*0.25),
        QPointF(x + wckl, y + hckl*0.25),
        QPointF(x + wckl, y + hckl*0.35),
        QPointF(x + wckl*0.7, y + hckl*0.65),
        QPointF(x + wckl*0.3, y + hckl*0.65),
        QPointF(x, y + hckl*0.35)
    };
    painter.drawPolygon(pointsckl, 14);
    //циклон
    xd = 650;
    x = xdev + xd;
    y = ydev;
    painter.drawRect(x, y, wfar + 2*wfar*0.1, hfar*0.2);
    x = xdev + wfar*0.1 + xd;
    y = ydev + hfar*0.2;
    static const QPointF pointsfar[6] = {
        QPointF(x, y),
        QPointF(x + wfar, y),
        QPointF(x + wfar, y + hfar*0.7),
        QPointF(x + wfar*0.8, y + hfar),
        QPointF(x + wfar*0.2, y + hfar),
        QPointF(x, y + hfar*0.7)
    };
    painter.drawPolygon(pointsfar, 6);

    //painter.save();

}


//void MainWindow::draw(int x, int y, int scale)
//{

//}


void MainWindow::on_pushButton_clicked()
{

    //repaint();
    update();
}

