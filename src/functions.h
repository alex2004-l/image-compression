#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "ppm_img.h"
#include "qtree.h"
#include "queue.h"

#define FILE_TYPE "P6"
#define MAX_RANGE 255

struct term_node_data {
    pixel pixel;
    unsigned char type;
};

struct int_node_data {
    unsigned char type;
};

qtree_node *create_int_node();
qtree_node *create_term_node(pixel p);
ppm_img *read_img(FILE *input_fp);
void write_img(FILE *fp, ppm_img *img);
qtree create_compression_tree(int factor, int size, int x, int y, ppm_img *img);
void write_compressed_file(FILE *output_fp, qtree tree, unsigned int size);
qtree qtree_from_compressed_img(FILE *fp);
void decompress_img(ppm_img *img, qtree tree, unsigned int x, unsigned int y, unsigned int size);

#endif