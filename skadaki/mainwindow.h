#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer*timer_cycle;
    qreal xdev, ydev;
    qreal wmc, hmc, scalemc;
    qreal wkld, hkld, scalekld;
    qreal wckl, hckl, scaleckl;
    qreal wfar, hfar, scalefar;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent*event);
    //void draw(int x, int y, int scale);
    void cycle();
};
#endif // MAINWINDOW_H
