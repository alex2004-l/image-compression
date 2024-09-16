#include "qtree.h"


qtree_node *create_qtree_node(void *data, size_t size) {
    qtree_node *new_node = malloc(sizeof(struct qtree));

    new_node->data = malloc(size);
    memcpy(new_node->data, data, size);
    new_node->size = size;

    new_node->children = malloc(CHILDREN * sizeof(struct qtree*));
    for (int i = 0; i < CHILDREN; ++i) {
        new_node->children[i] = NULL;
    }

    return new_node;
}


int qtree_height(qtree tree) {
    if (tree == NULL)
        return 0;
    
    int top_left = qtree_height(tree->children[0]);
    int top_right = qtree_height(tree->children[1]);
    int bottom_right = qtree_height(tree->children[2]);
    int bottom_left =qtree_height(tree->children[3]);

    return 1 + max4(top_left, top_right, bottom_right, bottom_left);
}


int check_leaf(qtree tree) {
    return (tree->children[0] == NULL) && (tree->children[1] == NULL) &&
        (tree->children[2] == NULL) && (tree->children[3] == NULL);
}


int qtree_leaf_count(qtree tree) {
    if (tree == NULL)
        return 0;

    if (check_leaf(tree))
        return 1;
    
    int top_left = qtree_leaf_count(tree->children[0]);
    int top_right = qtree_leaf_count(tree->children[1]);
    int bottom_right = qtree_leaf_count(tree->children[2]);
    int bottom_left = qtree_leaf_count(tree->children[3]);

    return top_left + top_right + bottom_left + bottom_right;
}


int qtree_min_depth(qtree tree) {
    if (tree == NULL)
        return 0;
    
    int top_left = qtree_min_depth(tree->children[0]);
    int top_right = qtree_min_depth(tree->children[1]);
    int bottom_right = qtree_min_depth(tree->children[2]);
    int bottom_left =qtree_min_depth(tree->children[3]);

    return 1 + min4(top_left, top_right, bottom_right, bottom_left);
}


void destroy_qtree(qtree tree) {
    if (tree == NULL)
        return;

    destroy_qtree(tree->children[0]);
    destroy_qtree(tree->children[1]);
    destroy_qtree(tree->children[2]);
    destroy_qtree(tree->children[3]);

    free(tree->children);
    free(tree->data);
    free(tree);
}