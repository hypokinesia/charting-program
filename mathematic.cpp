#include "mathematic.h"
#include "shedule.h"

mathematic::mathematic()
{
}

float mathematic::constant(float x, float y){

    float c = y-x*x/cos(x);
    return(c);
}
