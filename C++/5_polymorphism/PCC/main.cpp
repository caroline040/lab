///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/5_polymorphism/PCC/main.cpp
// 日期：2017-10
// 描述：使用多重继承，实现代码复用
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

#include <iostream>

#include "point.h"
#include "circle.h"
#include "cylinder.h"

using namespace std;

int main()
{
    point p(1, 2);
    cout << "点坐标：" << p << endl << endl;

    circle ci(5);
    ci.setRadius(3);
    cout << "圆的半径:" << ci.radius() << endl;
    cout << "圆的面积：" << ci.circleArea() << endl;
    cout << "圆的周长：" << ci.circlePerimeter() << endl << endl;

    cylinder cy(1, 4);
    cy.setRadius(2.1);
    cout << "圆的半径:" << cy.radius() << endl;
    cout << "圆的周长：" << cy.circlePerimeter() << endl;
    cout << "圆柱的高：" << cy.height() << endl;
    cout << "圆柱的表面积："<< cy.facialArea() << endl;
    cout << "圆柱的体积："  << cy.volume() << endl;

    return 0;
}

