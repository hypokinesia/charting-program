#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPalette>
#include <QMessageBox>
#include "shedule.h"
#include "mathematic.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QLabel *lbl;
    QLineEdit *lne_x, *lne_y;
    QPushButton *btn_build, *btn_about;
    shedule *shedul;
    mathematic *m;
private slots:
    void buildIt();
    void about();
public:
    float x, y, c;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
