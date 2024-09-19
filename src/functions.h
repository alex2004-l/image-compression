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

/* Wrapper function for creating an interior node in the tree */
qtree_node *create_int_node();

/* Wrapper function for creating a terminal node in the tree */
qtree_node *create_term_node(pixel p);

/* Reads a ppm image from an input file and creates a image element */
ppm_img *read_img(FILE *input_fp);

/* Writes the content of an image element in the output file */
void write_img(FILE *fp, ppm_img *img);

/* Creates compression tree for an image */
qtree create_compression_tree(int factor, int size, int x, int y, ppm_img *img);

/* Writes a compression tree in the output file */
void write_compressed_file(FILE *output_fp, qtree tree, unsigned int size);

/* Recreates a compression tree from a compressed file */
qtree qtree_from_compressed_img(FILE *fp);

/* Converts a compression tree in an image */
void decompress_img(ppm_img *img, qtree tree, unsigned int x, unsigned int y, unsigned int size);

#endif