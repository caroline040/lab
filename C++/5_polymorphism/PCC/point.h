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
