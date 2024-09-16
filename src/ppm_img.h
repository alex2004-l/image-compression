#ifndef PPM_IMG_H
#define PPM_IMG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pixel {
    unsigned char r, g, b;
} pixel;

typedef struct image {
    char file_type[20];
    unsigned int width, height;
    unsigned int max_range;
    pixel **matrix;
} ppm_img;


typedef unsigned char (*get_color_func)(pixel);

unsigned char get_red(pixel p);
unsigned char get_green(pixel p);
unsigned char get_blue(pixel p);


unsigned int get_color_score(unsigned int x, unsigned int y,
            unsigned int size, ppm_img *img, get_color_func get_color);
unsigned int get_red_score(unsigned int x, unsigned int y,
                            unsigned int size, ppm_img *img);
unsigned int get_blue_score(unsigned int x, unsigned int y,
                            unsigned int size, ppm_img *img);
unsigned int get_green_score(unsigned int x, unsigned int y,
                            unsigned int size, ppm_img *img);

unsigned long long get_mean_score(int x, int y, int size, ppm_img *img);

ppm_img *init_img(char *type, unsigned int height,
                    unsigned int width, unsigned char max_range);

void destroy_img(ppm_img *img);

#endif