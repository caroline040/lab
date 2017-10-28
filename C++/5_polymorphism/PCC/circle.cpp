///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/5_polymorphism/PCC/circle.cpp
// 日期：2017-10
// 描述：圆形circle类成员函数的实现
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

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
