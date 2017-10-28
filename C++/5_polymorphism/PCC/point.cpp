#include "point.h"

point::point(float x=0.0, float y=0.0) : _x(x), _y(y)
{

}

ostream &operator<<(ostream &out, const point &p)
{
    out << "(" << p.x() << ", " << p.y() << ")";
    return out;
}
