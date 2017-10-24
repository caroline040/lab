///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/3_class/line/line.h
// 日期：2017-10
// 描述：line类的设计
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

#ifndef LINE_H
#define LINE_H

#include "point.h"

class line
{
private:
    // 包含两个类对象，这是一种经典的"has-a"（复合）关系
    point p1;
    point p2;

public:
    line();
    line(point p1, point p2);

    double length() const;
};

#endif // LINE_H
