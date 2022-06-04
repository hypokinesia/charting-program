#include "shedule.h"
#include "mathematic.h"
#include "paintit.h"

shedule::shedule(QWidget *parent) : QWidget(parent)
{
    a = false;
    this->setWindowTitle("your shedule meow");
    this->resize(300, 300);
    this->setMinimumSize(200, 200);
    repaint();
    count = 0;
    xn = 100;
    yn = 100;
    m = new mathematic;
    pen1 = new QPen();
    pen2 = new QPen();
    pen1->setColor(Qt::red);
    pen2->setColor(Qt::blue);
    btn_plus = new QPushButton("+", this);
    btn_minus = new QPushButton("-", this);
    btn_plusX = new QPushButton("+x", this);
    btn_minusX = new QPushButton("-x", this);
    btn_plusY = new QPushButton("+y", this);
    btn_minusY = new QPushButton("-y", this);
    btn_plusX->setFixedWidth(30);
    btn_plusY->setFixedWidth(30);
    btn_minusX->setFixedWidth(30);
    btn_minusY->setFixedWidth(30);
    btn_plus->setFixedWidth(30);
    btn_minus->setFixedWidth(30);
    btn_minus->move(0,20);
    btn_plusX->move(0,40);
    btn_minusX->move(0,60);
    btn_plusY->move(0, 80);
    btn_minusY->move(0,100);
    btn_minusY->setEnabled(false);
    btn_minusX->setEnabled(false);
    btn_minus->setEnabled(false);
    menu = new QMenu(this);
    painter = new QPainter();
    editSheduleColor = new QAction("Редактировать цвет графика", this);
    editMarupColor = new QAction("Редактировать цвет сечений", this);
    savePicture = new QAction("Сохранить изображение", this);
    showNavigate = new QAction("Показать навигатор", this);
    paintTangent = new QAction("Включить режим касательной", this);


    connect(editSheduleColor, SIGNAL(triggered()), this, SLOT(edit()));
    connect(editMarupColor, SIGNAL(triggered()), this, SLOT(editM()));
    connect(savePicture , SIGNAL(triggered()), this, SLOT(save()));
    connect(showNavigate, SIGNAL(triggered()), this, SLOT(navigate()));
    connect(paintTangent, SIGNAL(triggered()), this, SLOT(tangent()));

    menu->addAction(editSheduleColor);
    menu->addAction(editMarupColor);
    menu->addAction(savePicture);
    menu->addAction(showNavigate);
    menu->addAction(paintTangent);


    numberX=20.0;
    numberY=20.0;

    connect(btn_plus, SIGNAL(clicked()), this, SLOT(plus()));
    connect(btn_minus, SIGNAL(clicked()), this, SLOT(minus()));
    connect(btn_plusX, SIGNAL(clicked()), this, SLOT(plusX()));
    connect(btn_minusX, SIGNAL(clicked()), this, SLOT(minusX()));
    connect(btn_plusY, SIGNAL(clicked()), this, SLOT(plusY()));
    connect(btn_minusY, SIGNAL(clicked()), this, SLOT(minusY()));

    setMouseTracking(true);

}
void shedule::plusX(){
    btn_minusX->setEnabled(true);
    numberX+=20.0;
    if (numberX>=290.0){
        btn_plusX->setEnabled(false);
        btn_plus->setEnabled(false);
    }
    repaint();
}
void shedule::minusX(){
    btn_plusX->setEnabled(true);
    numberX-=20.0;
    if (numberX<=30.0){
        btn_minusX->setEnabled(false);
        btn_minus->setEnabled(false);
    }
    repaint();
}
void shedule::plusY(){
    btn_minusY->setEnabled(true);
    numberY+=20.0;
    if (numberY>=290.0){
        btn_plusY->setEnabled(false);
        btn_plus->setEnabled(false);
    }
    repaint();
}
void shedule::minusY(){
    btn_plusY->setEnabled(true);
    numberY-=20.0;
    if (numberY<=30.0){
        btn_minusY->setEnabled(false);
        btn_minus->setEnabled(false);
    }
    repaint();
}
void shedule::keyPressEvent(QKeyEvent *e){
    if(Qt::Key_S==e->key()){
        save();
    }
    if(Qt::Key_N==e->key()){
        navigate();
    }
    if(Qt::Key_T==e->key()){
        tangent();
    }
    if(Qt::Key_A==e->key()){
    QMessageBox msgBox;
    msgBox.setText("Привет, это программа для построения графиков! "
                   "Правой кнопкой мыши вы можете "
                   "вызвать контекстное меню для настройки цвета и "
                   "отображеня навигатора, что "
                   "также возможно сделать по кнопке N. Помимо этого "
                   "доступно сохранение результата "
                   "в виде фото. Для быстрого доступа нажмите S");
    msgBox.exec();}
}
void shedule::tangent(){
    if(!a){a = true;
    btn_plus->hide();
    btn_minus->hide();
    btn_plusX->hide();
    btn_minusX->hide();
    btn_plusY->hide();
    btn_minusY->hide();
    paintTangent->setText("Отключить режим касательной");}
    else if(a){
        a = false;
        repaint();
        btn_plus->show();
        btn_minus->show();
        btn_plusX->show();
        btn_minusX->show();
        btn_plusY->show();
        btn_minusY->show();
        paintTangent->setText("Включить режим касательной");
    }
}
void shedule::mousePressEvent(QMouseEvent *e){
    if(Qt::RightButton&e->button()){
            menu->exec(e->globalPos());
        }
    if(Qt::LeftButton&e->button()&&a==true){
        xt = e->pos().x();
        yt = e->pos().y();
    }
}
void shedule::edit(){
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    pen2->setColor(color);
    repaint();

}

void shedule::editM(){
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    pen1->setColor(color);
    repaint();

}
void shedule::save(){
    btn_minus->hide();
    btn_plus->hide();
    btn_minusX->hide();
    btn_plusX->hide();
    btn_minusY->hide();
    btn_plusY->hide();
    QFileDialog dialog;
    QString l;
    l = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        "/home",
                                                        tr("Images (*.png *.xpm *.jpg)"));
    QImage img(this->size(), QImage::Format_ARGB32);
    QPainter painter(&img);
    this->render(&painter);
    img.save(l);
    btn_minus->show();
    btn_plus->show();
    btn_minusX->show();
    btn_plusX->show();
    btn_minusY->show();
    btn_plusY->show();

}
void shedule::navigate(){
    if (count == 0){
        count = 1;
        showNavigate->setText("Скрыть навигатор");
        repaint();
    }
    else{
        count = 0;
        showNavigate->setText("Показать навигатор");
        repaint();
    }
}
void shedule::plus(){
    btn_minus->setEnabled(true);
    btn_minusX->setEnabled(true);
    btn_minusY->setEnabled(true);
    numberX+=20.0;
    numberY = numberX;
    if (numberX>=290.0){
        btn_plus->setEnabled(false);
        btn_plusX->setEnabled(false);
        btn_plusY->setEnabled(false);
    }
    repaint();
}

void shedule::minus(){
    btn_plus->setEnabled(true);
    numberX-=20.0;
    numberY = numberX;
    if (numberX<=30.0){
        btn_minus->setEnabled(false);
    }
    repaint();
}
void shedule::mouseMoveEvent(QMouseEvent *e){
    bool leftClick = e->buttons() & Qt::LeftButton;
    if(leftClick)
    {
        xn = e->pos().x();
        yn = e->pos().y();
        repaint();
    }
}
void shedule::paintEvent(QPaintEvent *e){
    h=this->height();
    w=this->width();
    onecooX=h/numberX;
    onecooY=h/numberY;
    QPainter *painter;
    painter = new QPainter();
    painter->begin(this);
    paintIt().shedulePaint(painter, h, w, numberX, numberY, onecooX, onecooY, c, pen1, pen2, a, xt, yt);
    if(count==1)
    {
        paintIt().paintNavigate(painter, xn, yn, h, onecooX, onecooY);
    }
    painter->end();

}
void shedule::resizeEvent(QResizeEvent *event){
    if(event->size().width()!=event->size().height()){
        this->resize(event->size().height(), event->size().height());
    }
    repaint();
}
