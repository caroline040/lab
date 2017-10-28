#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class cylinder : public circle
{
private:
    float _height;

public:
    // 底面圆心坐标默认为(0, 0)
    cylinder(float r, float h, float x=0, float y=0);

    // 设置和获取高度
    void setHeight(float h){_height = h;}
    float height()const{return _height;}

    // 获取表面积和体积
    float facialArea();
    float volume();
};

#endif // CYLINDER_H
