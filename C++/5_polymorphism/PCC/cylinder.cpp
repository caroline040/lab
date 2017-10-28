#include "cylinder.h"

cylinder::cylinder(float r, float h, float x, float y)
    : circle(r, x, y)
{
    _height = h;
}

float cylinder::facialArea()
{
    return 2*this->circleArea() + this->circlePerimeter()*height();
}

float cylinder::volume()
{
    return this->circleArea() * height();
}
