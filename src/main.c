/* Tema 2 - Structuri de Date și Algoritmi - Arbore cuaternar de compresie
LACHE Alexandra Florentina Georgiana, 311 CD, UPB ACS 2022-2023 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define MIN_ARGS 4
#define MAX_ARGS 5


static inline void close_files(FILE *input, FILE *output) {
    fclose(input);
    fclose(output);
}


void solve_c1(FILE *input, FILE *output, int factor) {
    ppm_img *img = read_img(input);

    qtree tree = create_compression_tree(factor, img->height, 0, 0, img);

    fprintf(output, "%d\n%d\n%d\n", qtree_height(tree),
            qtree_leaf_count(tree), img->height >> (qtree_min_depth(tree) - 1));
    destroy_qtree(tree);
    destroy_img(img);
}


void solve_c2(FILE *input, FILE *output, int factor) {
    ppm_img *img = read_img(input);

    qtree tree = create_compression_tree(factor, img->height, 0, 0, img);
    write_compressed_file(output, tree, img->height);

    destroy_qtree(tree);
    destroy_img(img);
}


void solve_d(FILE *input, FILE *output) {
    unsigned int size;
    fread(&size, sizeof(unsigned int), 1, input);

    ppm_img *img = init_img(FILE_TYPE, size, size, MAX_RANGE);
    qtree tree = qtree_from_compressed_img(input);
    decompress_img(img, tree, 0, 0, size);
    write_img(output, img);

    destroy_qtree(tree);
    destroy_img(img);

}


int main(int argc, const char *argv[]) {

    setvbuf(stdout, NULL, _IONBF, 0);

    if (argc < MIN_ARGS || argc > MAX_ARGS) {
        fprintf(stderr,
            "Wrong argument count!!\nUsage: ./quadtree [-c1 factor | -c2 factor | -d] [input_fp] [output_fp]\n");
        return -1;
    }

    int factor;
    FILE *input_fp, *output_fp;

    if (!strcmp(argv[1], "-c1")) {
        factor = atoi(argv[2]);

        input_fp = fopen(argv[3], "rb");
        if (input_fp == NULL) {
            fprintf(stderr, "ERROR: Cannot open %s!", argv[3]);
            return -1;
        }

        output_fp = fopen(argv[4], "wt");
        if (output_fp == NULL) {
            fprintf(stderr, "ERROR: Cannot open %s!", argv[4]);
            return -1;
        }

        solve_c1(input_fp, output_fp, factor);

        close_files(input_fp, output_fp);
    } else if (!strcmp(argv[1], "-c2")) {
        factor = atoi(argv[2]);

        input_fp = fopen(argv[3], "rb");
        if (input_fp == NULL) {
            fprintf(stderr, "ERROR: Cannot open %s!", argv[3]);
            return -1;
        }

        output_fp = fopen(argv[4], "wb");
        if (output_fp == NULL) {
            fprintf(stderr, "ERROR: Cannot open %s!", argv[4]);
            return -1;
        }

        solve_c2(input_fp, output_fp, factor);

        close_files(input_fp, output_fp);
    } else if (!strcmp(argv[1], "-d")) {
        input_fp = fopen(argv[2], "rb");
        if (input_fp == NULL) {
            fprintf(stderr, "ERROR: Cannot open %s!", argv[3]);
            return -1;
        }

        output_fp = fopen(argv[3], "wb");
        if (output_fp == NULL) {
            fprintf(stderr, "ERROR: Cannot open %s!", argv[4]);
            return -1;
        }

        solve_d(input_fp, output_fp);

        close_files(input_fp, output_fp);
    } else {
        fprintf(stderr, "ERROR: Unknown argument!");
        return -1;
    }

    return 0;
}