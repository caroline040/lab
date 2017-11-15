#include "example.h"
#include <QDebug>

int example::publicFunc()
{
    return 0;
}

int example::protectedFunc()
{
    return 0;
}

int example::privateFunc()
{
    return 0;
}

int example::publicSlot()
{
    qDebug() << __FUNCTION__;
    return 0;
}

int example::protectedSlot()
{
    qDebug() << __FUNCTION__;
    return 0;
}

int example::privateSlot()
{
    qDebug() << __FUNCTION__;
    return 0;
}
