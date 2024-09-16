#ifndef QTREE_H
#define QTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHILDREN 4

typedef struct qtree {
    void *data;
    size_t size;
    struct qtree **children;
} qtree_node, *qtree;


static inline int max4(int a, int b, int c, int d) {
    int max_ab = (b > a) ? b : a;
    int max_cd = (d > c) ? d : c;
    return (max_ab > max_cd) ? max_ab : max_cd;
}

static inline int min4(int a, int b, int c, int d) {
    int min_ab = (b > a) ? a : b;
    int min_cd = (d > c) ? c : d;
    return (min_ab > min_cd) ? min_cd : min_ab;
}

qtree_node *create_qtree_node(void *data, size_t size);
int qtree_height(qtree tree);
int check_leaf(qtree tree);
int qtree_leaf_count(qtree tree);
int qtree_min_depth(qtree tree);
void destroy_qtree(qtree tree);

#endif