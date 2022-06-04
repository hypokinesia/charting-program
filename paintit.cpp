#include "paintit.h"
#include "shedule.h"

paintIt::paintIt()
{
}
void paintIt::paintNavigate(QPainter *painter, int xn, int yn, int h, float onecooX, float onecooY){
    painter->drawLine(xn-5, yn-5, xn+5, yn+5);
    painter->drawLine(xn+5, yn-5, xn-5, yn+5);
    float k = round(((h/2-yn)/onecooY)*10)/10;
    float g = round(((xn-h/2)/onecooX)*10)/10;
    QString s = QString::number(k);
    QString f = QString::number(g);
    painter->drawText(xn+10, yn, f+" "+s);
}
void paintIt::shedulePaint(QPainter *painter, int h, int w, int numberX, int numberY, float onecooX, float onecooY, float c, QPen *pen1, QPen *pen2, bool a, int x, int y){
    if (a){
        bool pr = false;
        float xO = 0;
        float ytangent;
        float Ai;
        for (int i = x-3; i<=x+3; i++){
           float Ai =i/onecooX - numberX/2;
           ytangent = (Ai*Ai)/cos(Ai)+c;

           if(h/2-ytangent*onecooY<h && h/2-ytangent*onecooY>0){
               if(h/2-ytangent*onecooY<y+10 && h/2-ytangent*onecooY>y-10){
               xO = Ai;
               pr = true;}
           }
        }
        if(!pr){
            painter->drawText(0, 20, "Выберите точку на графике");
        }
        painter->drawText(0,40,QString::number(xO));
        if(pr){
            for(float i=-numberX/2; i<numberX/2; i+=0.01){
                if(cos(i)!=0){
                float ykOne = (((xO*xO)/cos(xO)+c)+(((2*xO*cos(xO))+(xO*xO)*sin(xO))/(cos(xO)*cos(xO)))*(i-xO));
                float ykTwo = (((xO*xO)/cos(xO)+c)+(((2*xO*cos(xO))+(xO*xO)*sin(xO))/(cos(xO)*cos(xO)))*((i+0.1)-xO));
                if(h/2+i*onecooX<w && h/2-ykOne*onecooY>0 && h/2+(i+0.1)*onecooX<h && h/2-ykTwo*onecooY>0){
                painter->drawLine(h/2+i*onecooX, h/2-ykOne*onecooY, h/2+(i+0.1)*onecooX, h/2-ykTwo*onecooY);}}
            }
        }
    }
    painter->drawLine(0, h/2, w, h/2);
    painter->drawLine(w/2, 0, w/2, h);
    painter->drawText(h/2-10, 15, "y");
    painter->drawText(w-20, h/2-15, "x");
    int l=w/2;
    int counter = 0;
    painter->setPen(*pen1);
    while (l<=w){
        if(counter!=0) {
        painter->drawLine(l, h/2+5, l, h/2-5);
        QString s = QString::number(counter);
        painter->drawText(l, h/2+15, s);}
        l+=onecooX*round(numberX/2/10);
        counter+=round(numberX/2/10);
    }
    l=w/2;
    counter = 0;
    while (l>0){
        if(counter!=0) {
        painter->drawLine(l, h/2+5, l, h/2-5);
        QString s = QString::number(counter);
        painter->drawText(l, h/2+15, s);}
        l-=onecooX*round(numberX/2/10);
        counter+=round(numberX/2/10);
    }
    l=h/2;
    counter = 0;
    while (l<h){
        QString s = QString::number(counter);
        if(counter!=0) {
        painter->drawText(w/2+10, l-5, s);
        painter->drawLine(w/2+5, l, w/2-5, l);}
        l+=onecooY*round(numberY/2/10);
        counter+=round(numberY/2/10);
    }
    l=h/2;
    counter = 0;
    while (l>0){
        QString s = QString::number(counter);
        if(counter!=0) {
        painter->drawText(w/2+10, l+5, s);
        painter->drawLine(w/2+5, l, w/2-5, l);}
        l-=onecooY*round(numberY/2/10);
        counter+=round(numberY/2/10);
    }
    painter->setPen(*pen2);
    for(float i=-numberX/2; i<numberX/2; i+=0.001){
        if(cos(i)!=0){
        float ykOne = (i*i)/cos(i)+c;
        float ykTwo = ((i+0.001)*(i+0.001))/cos(i+0.001)+c;
        if(ykOne<=numberY/2 && ykOne>=-numberY/2 && ykTwo<=numberY/2 && ykTwo>=-numberY/2){
        painter->drawLine(h/2+i*onecooX, h/2-ykOne*onecooY, h/2+(i+0.001)*onecooX, h/2-ykTwo*onecooY);}}
    }
}
