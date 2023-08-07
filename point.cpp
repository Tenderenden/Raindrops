#include "point.h"

point::setX(int x)
{
    pos_x = x;
}

point::setY(int y)
{
    pos_y = y;
}

point::point(int x, int y)
{
    pos_x = x;
    pos_y = y;
}

point::~point()
{
}