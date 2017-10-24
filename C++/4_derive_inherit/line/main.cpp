///////////////////////////////////////////////////////////
//
// Copyright(C) 2013-2017, GEC Tech. Co., Ltd.
//
// 文件：lab/C++/3_class/line/main.cpp
// 日期：2017-10
// 描述：使用线段，包含点，体会has-a逻辑关系
//
// 作者：Vincent Lin（林世霖） 微信公众号：秘籍酷
// 技术微店：http://weidian.com/?userid=260920190
// 技术交流：260492823（QQ群）
//
///////////////////////////////////////////////////////////

#include <iostream>
#include "point.h"
#include "line.h"

using namespace std;

int main()
{
    point p1;
    point p2(1,2);
    point p3(3,4);

    line l1;
    line l2(p1, p2);
    line l3(p1, p3);

    cout << l1.length() << endl;
    cout << l2.length() << endl;
    cout << l3.length() << endl;

    return 0;
}
