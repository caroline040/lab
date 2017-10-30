#include <iostream>
#include <fstream>

#include <cstdio>
#include <cstdbool>
#include <cerrno>

#include "wrap.h"

using namespace std;

int width, height, bpp;

void usage(int argc, char **argv)
{
    if(argc != 2)
    {
        cout << "用法：%s <JPG/JPEG格式图片>" << argv[0] << endl;
        exit(0);
    }
}

char *decompress_jpg(ifstream &jpg)
{
    // 1，分配一块与文件大小的内存
    jpg.seekg(0, ios::end);
    long len = jpg.tellg();

    char *jpgdata = new char[len];
    jpg.seekg(0, ios::beg);

    // 2，讲JPG图片数据全部读出
    jpg.read(jpgdata, len);
    if(jpg.bad())
    {
        cerr << "读取JPG数据失败！" << endl;
        exit(0);
    }

    // 3，开始使用JPG库，将图片数据解码成RGB格式
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    jpeg_mem_src(&cinfo, (unsigned char *)jpgdata, len);

    if(jpeg_read_header(&cinfo, true) != 1)
    {
        cerr << "该文件不是JPEG格式图片，你逗我？" << endl;
        exit(0);
    }

    jpeg_start_decompress(&cinfo);

    width = cinfo.output_width;
    height= cinfo.output_height;
    bpp   = cinfo.output_components * 8;

    int row_stride = width * bpp/8;

    char *rgb = new char[row_stride * height];

    while(cinfo.output_scanline < cinfo.output_height)
    {
        char *buffer_array[1];
        buffer_array[0] = rgb + cinfo.output_scanline*row_stride;

        jpeg_read_scanlines(&cinfo, (unsigned char **)buffer_array, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    delete [] jpgdata;

    return rgb;
}

void display(char *rgb)
{
    ofstream lcd;
    lcd.open("/dev/fb0");

    if(lcd.bad())
    {
        perror("打开LCD失败");
        exit(0);
    }

    for(int line=0; line<480; ++line)
    {
        for(int col=0; col<800; ++col)
        {
            lcd.write(rgb+col*bpp/8+line*width*bpp/8+1, 1);
            lcd.write(rgb+col*bpp/8+line*width*bpp/8+2, 1);
            lcd.write(rgb+col*bpp/8+line*width*bpp/8+0, 1);

            lcd.seekp(1, ios_base::cur);
        }
    }

    lcd.flush();
    lcd.close();
}

int main(int argc, char **argv)
{
    usage(argc, argv);

    // 初始化LCD
    struct fb_var_screeninfo vinfo;
    char *fbmem = NULL;
    if(!lcd_init(&vinfo, &fbmem))
    {
        exit(0);
    }

    // 解码并显示JPG图片
    char *rgb = NULL;
    struct image_info imginfo;
    decompress_jpg(argv[1], &rgb, &imginfo);
    write_lcd(rgb, &imginfo, fbmem, &vinfo);

    /*
    ifstream jpg;
    jpg.open(argv[1], ios_base::binary);

    if(!jpg.is_open())
    {
        cout << "打开图片失败！" << endl;
        exit(0);
    }

    // 解码JPG数据
    char *rgb = decompress_jpg(jpg);
    display(rgb);

    delete [] rgb;
    */

    return 0;
}

