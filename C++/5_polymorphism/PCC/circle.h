#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class circle : public point
{
private:
    float _radius;

    const float PI = 3.141592654;

public:
    // 圆心坐标默认为(0, 0)
    circle(float r, float x=0, float y=0);

    // 设置和获取半径
    void setRadius(float r){_radius = r;}
    float radius()const{return _radius;}

    // 计算并获取圆面积和圆周长
    float circleArea();
    float circlePerimeter();
};

#endif // CIRCLE_H
