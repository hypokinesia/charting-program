#ifndef SHEDULE_H
#define SHEDULE_H

#include <QWidget>
#include <QKeyEvent>
#include "mathematic.h"
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QResizeEvent>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QFileDialog>
#include <QImage>
#include <QColor>
#include <QPen>
#include <QMainWindow>
#include <QColorDialog>
#include <QMessageBox>
#include <QWheelEvent>

class shedule : public QWidget
{
    Q_OBJECT
private:
    mathematic *m;
    QPushButton *btn_plus, *btn_minus, *btn_plusX, *btn_minusX, *btn_plusY, *btn_minusY;
    QMenu *menu;
    QAction *editSheduleColor, *savePicture, *showNavigate, *editMarupColor, *paintTangent;
    QPainter *painter;
    QPen *pen1, *pen2;

    float numberX, numberY, onecooX, onecooY;
    int h, w, count, xn, yn, xt, yt;
    bool a;

protected:
    void keyPressEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private slots:
    void tangent();
    void plus();
    void minus();
    void save();
    void navigate();
    void edit();
    void editM();
    void plusX();
    void plusY();
    void minusX();
    void minusY();
public:
    float c;
    explicit shedule(QWidget *parent = nullptr);
};

#endif // SHEDULE_H
