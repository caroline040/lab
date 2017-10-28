///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/5_polymorphism/PCC/point.h
// 日期：2017-10
// 描述：点point类的设计
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class point
{
private:
    float _x;
    float _y;

public:
    point(float x, float y);

    void setX(float x){_x = x;}
    void setY(float y){_y = y;}

    float x()const{return _x;}
    float y()const{return _y;}

    friend ostream &operator<<(ostream &out, const point &p);
};

#endif // POINT_H
