///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/3_class/line/line.cpp
// 日期：2017-10
// 描述：line类成员函数的实现
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

#include "line.h"
#include <cmath>

line::line()
{
}

line::line(point p1, point p2) : p1(p1), p2(p2)
{}


double line::length() const
{
    int x_delta = p1.x() - p2.x();
    int y_delta = p1.y() - p2.y();

    return sqrt(x_delta * x_delta + y_delta * y_delta);
}
