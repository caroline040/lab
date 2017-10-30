#ifndef LCD_H
#define LCD_H

#include "wrap.h"

class LCD
{
private:
    int _fd;
    char *_fbmem;
    struct fb_var_screeninfo *_vinfo;

public:
    LCD();
    ~LCD();

    int fd()const{ return _fd;}
    char *fbmem()const{ return _fbmem;}
    struct fb_var_screeninfo *screenInfo()const{return _vinfo;}

    u_int32_t screenSize()const;
};

#endif // LCD_H
