///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/5_polymorphism/complexNumber/complexNumber.h
// 日期：2017-10
// 描述：复数类complexNumber的设计
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

using namespace std;

class complexNumber
{
private:
    float realNumber;
    float imaginaryUnit;

public:
    complexNumber(float r=0, float i=0);

    void setValue(float r, float i);

    complexNumber operator+(const complexNumber &c);
    complexNumber operator-(const complexNumber &c);
    complexNumber operator*(const complexNumber &c);
    complexNumber operator/(const complexNumber &c);
    complexNumber &operator=(const complexNumber &c);

    // 为了符合标准输出的习惯，讲operator<<声明为友元函数
    friend ostream &operator<<(ostream &o, const complexNumber &c);
};

#endif // COMPLEXNUMBER_H
