//Проверка ввода начальных значений
//Закрытие окна графика, если главное окно закрыто
//Сохранение изображений


#include "mainwindow.h"

#include <QApplication>
#include <QColor>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(w.windowFlags()&~Qt::WindowMaximizeButtonHint);
    w.setWindowTitle("your shedule meow");
    w.show();
    return a.exec();
}
