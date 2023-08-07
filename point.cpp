#include "point.h"

point::setX(int x)
{
    pos_x = x;
}

point::setY(int y)
{
    pos_y = y;
}

point::setV(int v)
{
    velocity = v;
}

point::point(int x, int y, int v, int t)
{
    pos_x = x;
    pos_y = y;
    velocity = v;
    tail = t;
}

point::~point()
{
}