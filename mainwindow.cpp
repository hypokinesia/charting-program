#include "mainwindow.h"
#include "shedule.h"
#include "mathematic.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(200, 150);
    shedul = new shedule;
    lne_x = new QLineEdit("enter x", this);
    lne_y = new QLineEdit("enter y", this);
    btn_build = new QPushButton("build it!", this);
    btn_about = new QPushButton("?", this);
    btn_about->setFixedWidth(20);
    btn_about->move(this->width()-20, 0);
    lbl = new QLabel("y = (x^2)/cos(x) +c", this);
    lne_x->setFixedSize(200, 30);
    lne_y->setFixedSize(200, 30);
    btn_build->setFixedSize(200, 30);
    lbl->setSizeIncrement(300,300);

    lne_x->move(0,30);
    lne_y->move(0,70);
    btn_build->move(0, 110);

    connect(btn_build, SIGNAL(clicked()), this, SLOT(buildIt()));
    connect(btn_about, SIGNAL(clicked()), this, SLOT(about()));
}
void MainWindow::about(){
    QMessageBox msgBox;
    msgBox.setText("Привет, это программа для построения графиков! "
                   "Правой кнопкой мыши вы можете "
                   "вызвать контекстное меню для настройки цвета и "
                   "отображеня навигатора, что "
                   "также возможно сделать по кнопке N. Помимо этого "
                   "доступно сохранение результата "
                   "в виде фото. Для быстрого доступа нажмите O");
    msgBox.exec();
}


void MainWindow::buildIt(){
    if(lne_x->text().toFloat() && lne_y->text().toFloat()) {
        x = lne_x->text().toFloat();
        y = lne_y->text().toFloat();
        m = new mathematic();
        c = m->constant(x, y);
        shedul->c = c;
        lbl->setFixedWidth(300);
        QString l = "y = (x^2)/cos(x)";
        lbl->setText(l+QString::number(c));
        shedul->show();
        shedul->update();
    }
    else if(lne_x->text()=="0" && lne_y->text()=="0"){
            x = lne_x->text().toFloat();
            y = lne_y->text().toFloat();
            m = new mathematic();
            c = m->constant(x, y);
            shedul->c = c;
            lbl->setFixedWidth(300);
            QString l = "y = (x^2)/cos(x)";
            lbl->setText(l+QString::number(c));
            shedul->show();
            shedul->update();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Неправильно введено значение");
        msgBox.exec();
    }

}

MainWindow::~MainWindow()
{
}

