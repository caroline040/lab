///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/5_polymorphism/PCC/cylinder.cpp
// 日期：2017-10
// 描述：圆柱形cylinder类成员函数的实现
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

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
