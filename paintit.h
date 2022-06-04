#ifndef PAINTIT_H
#define PAINTIT_H

#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <shedule.h>



class paintIt
{
public:
    paintIt();
    void paintNavigate(QPainter *painter, int xn, int yn, int h, float onecooX, float onecooY);
    void shedulePaint(QPainter *painter, int h, int w, int numberX, int numberY, float onecooX, float onecooY, float c, QPen *pen1, QPen *pen2, bool a, int xt, int yt);
};

#endif // PAINTIT_H
