#include "circle.h"

circle::circle(float r, float x, float y):point(x, y)
{
    _radius = r;
}

float circle::circleArea()
{
    return PI * _radius * _radius;
}

float circle::circlePerimeter()
{
    return 2 * PI * _radius;
}
