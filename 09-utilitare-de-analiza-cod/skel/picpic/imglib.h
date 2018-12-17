#ifndef _IMGLIB_0
#define _IMGLIB_0

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>
#include <sys/queue.h>

typedef unsigned char pixel_t;

typedef struct
{
  unsigned int width;
  unsigned int height;
  pixel_t *buf;
} image_t;

typedef image_t *image;

image alloc_img (unsigned int width, unsigned int height);
void free_img (image);
void fill_img (image img, pixel_t pixel);
void fill_img_incr (image img);
image read_ppm (FILE * pf);
void write_ppm (FILE * fd, image img);

#define GET_PIXEL(IMG, X, Y) (IMG->buf[ ((Y) * IMG->width + (X)) ])
#define PPMREADBUFLEN 256
#endif
