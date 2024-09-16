#include "ppm_img.h"


unsigned char get_red(pixel p) { return p.r;}
unsigned char get_green(pixel p) { return p.g;}
unsigned char get_blue(pixel p) { return p.b;}


unsigned int get_color_score(unsigned int x, unsigned int y,
            unsigned int size, ppm_img *img, get_color_func get_color) {

    pixel **matrix = img->matrix;
    unsigned long long sum = 0;

    for (int i = x; i < x + size; ++i)
        for (int j = y; j < y + size; ++j)
            sum += get_color(matrix[i][j]);
    
    sum = sum / (size * size);
    return (unsigned int) sum;
}


unsigned int get_red_score(unsigned int x, unsigned int y,
                            unsigned int size, ppm_img *img) {
    return get_color_score(x, y, size, img, get_red);
}

unsigned int get_blue_score(unsigned int x, unsigned int y,
                            unsigned int size, ppm_img *img) {
    return get_color_score(x, y, size, img, get_blue);
}

unsigned int get_green_score(unsigned int x, unsigned int y,
                            unsigned int size, ppm_img *img) {
    return get_color_score(x, y, size, img, get_green);
}


unsigned long long get_mean_score(int x, int y, int size, ppm_img *img) {
    pixel **matrix = img->matrix;

    unsigned int red = get_red_score(x, y, size, img);
    unsigned int green = get_green_score(x, y, size, img);
    unsigned int blue = get_blue_score(x, y, size, img);

    unsigned long long result = 0;
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            result += (red - matrix[i][j].r) * (red - matrix[i][j].r)
            + (green - matrix[i][j].g) * (green - matrix[i][j].g) 
            + (blue - matrix[i][j].b) * (blue - matrix[i][j].b);
        }
    }

    result /= (3 * size * size);
    return result;
}

ppm_img *init_img(char *type, unsigned int height,
                    unsigned int width, unsigned char max_range) {
    ppm_img *img = malloc(sizeof(struct image));

    strcpy(img->file_type, type);
    img->height = height;
    img->width = width;
    img->max_range = max_range;

    img->matrix = malloc(sizeof(pixel *) * height);
    
    for (int i = 0; i < height; ++i) {
        img->matrix[i] = malloc(sizeof(pixel) * width);
    }

    return img;
}


void destroy_img(ppm_img *img) {
    for (int i = 0; i < img->height; ++i) {
        free(img->matrix[i]);
    }
    free(img->matrix);
    free(img);
}