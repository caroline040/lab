CC = arm-none-linux-gnueabi-gcc

CPPFLAGS += -I../jpeg/include

LDFLAGS += -L../jpeg/lib
LDFLAGS += -Wl,-rpath=.

all:v4l2_jpeg_videostream v4l2_yuv_videostream

v4l2_jpeg_videostream:v4l2_jpeg_videostream.c
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS) -ljpeg

v4l2_yuv_videostream:v4l2_yuv_videostream.c
	$(CC) $^ -o $@ $(CPPFLAGS) $(LDFLAGS) -lSDL


clean:
	$(RM) v4l2_jpeg_videostream v4l2_yuv_videostream
