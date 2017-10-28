///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/5_polymorphism/PCC/point.cpp
// 日期：2017-10
// 描述：点point类成员函数的实现
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

#include "point.h"

point::point(float x=0.0, float y=0.0) : _x(x), _y(y)
{

}

ostream &operator<<(ostream &out, const point &p)
{
    out << "(" << p.x() << ", " << p.y() << ")";
    return out;
}
