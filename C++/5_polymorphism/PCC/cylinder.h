///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/5_polymorphism/PCC/cylinder.h
// 日期：2017-10
// 描述：圆柱形cylinder类的设计
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

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
