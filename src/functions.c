#include "functions.h"


qtree_node *create_int_node() {
    struct int_node_data data;
    data.type = 0;

    return create_qtree_node(&data, sizeof(struct int_node_data));
}


qtree_node *create_term_node(pixel p) {
    struct term_node_data data;
    data.type = 1;
    data.pixel = p;

    return create_qtree_node(&data, sizeof(struct term_node_data));
}


ppm_img *read_img(FILE *input_fp) {
    char file_type[20];
    unsigned int width, height;
    unsigned char max_range;

    fscanf(input_fp, "%s", file_type);
    fscanf(input_fp, "%d%d", &width, &height);
    fscanf(input_fp, "%hhu", &max_range);

    fgetc(input_fp);
    printf("%s %hhu", file_type, max_range);

    ppm_img *img = init_img(file_type, height, width, max_range);

    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            fread(&(img->matrix[i][j]), sizeof(unsigned char), 3, input_fp);
    
    return img;
}


void write_img(FILE *fp, ppm_img *img) {
    fprintf(fp, "%s\n", img->file_type);
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "%d\n", img->max_range);
    for (int i = 0; i < img->height; ++i) 
        for (int j = 0; j < img->width; ++j)
            fwrite(&(img->matrix[i][j]), sizeof(unsigned char), 3, fp);
}


qtree create_compression_tree(int factor, int size, int x, int y, ppm_img *img) {
    unsigned long long mean_score = get_mean_score(x, y, size, img);

    if (mean_score > factor) {
        qtree_node *node = create_int_node();

        node->children[0] = create_compression_tree(factor, size/2, x, y, img);
        node->children[1] = create_compression_tree(factor, size/2, x, y + size/2, img);
        node->children[2] = create_compression_tree(factor, size/2, x + size/2, y + size/2, img);
        node->children[3] = create_compression_tree(factor, size/2, x + size/2, y, img);

        return node;
    } else {
        pixel p;

        p.r = get_red_score(x, y, size, img);
        p.g = get_green_score(x, y, size, img);
        p.b = get_blue_score(x, y, size, img);

        return create_term_node(p);
    }
}


void write_compressed_file(FILE *output_fp, qtree tree, unsigned int size) {
    fwrite(&size, sizeof(unsigned int), 1, output_fp);

    queue q = init_queue();
    enqueue(&q, tree, sizeof(struct qtree));

    while (q->size != 0) {
        qnode *node = dequeue(q);
        qtree_node *qt_node = (qtree_node *) node->data;

        if (qt_node->size == sizeof(struct int_node_data)) {
            enqueue(&q, qt_node->children[0], sizeof(struct qtree));
            enqueue(&q, qt_node->children[1], sizeof(struct qtree));
            enqueue(&q, qt_node->children[2], sizeof(struct qtree));
            enqueue(&q, qt_node->children[3], sizeof(struct qtree));

            struct int_node_data *data = (struct int_node_data*) qt_node->data;
            fwrite(&(data->type), sizeof(unsigned char), 1, output_fp);
        } else {
            struct term_node_data *data = (struct term_node_data*) qt_node->data;

            fwrite(&(data->type), sizeof(unsigned char), 1, output_fp);
            fwrite(&(data->pixel), sizeof(unsigned char), 3, output_fp);
        }
        destroy_queue_node(node);
    }

    destroy_queue(q);
}


qtree qtree_from_compressed_img(FILE *fp) {
    qtree tree;
    queue q = init_queue();

    unsigned char type;
    fread(&type, sizeof(unsigned char), 1, fp);

    if (type == 0) {
        tree = create_int_node(); 
        enqueue(&q, tree, sizeof(struct qtree)); 
    } else {
        pixel p;
        fread(&p, sizeof(unsigned char), 3, fp);

        tree = create_term_node(p);
    }

    while(!queue_is_empty(q)) {
        qnode *node = dequeue(q);
        qtree_node *qt_node = (qtree_node *) node->data;

        for (int i = 0; i < CHILDREN; ++i) {
            fread(&type, sizeof(unsigned char), 1, fp);

            if (type == 0) {
                qt_node->children[i] = create_int_node();
                enqueue(&q, qt_node->children[i], sizeof(struct qtree));
            } else {
                pixel p;
                fread(&p, sizeof(unsigned char), 3, fp);
                qt_node->children[i] = create_term_node(p);
            }
        }

        destroy_queue_node(node);
    }

    destroy_queue(q);
    return tree;
}


void decompress_img(ppm_img *img, qtree tree, unsigned int x, unsigned int y, unsigned int size) {
    if (tree->size == sizeof(struct int_node_data)) {
        decompress_img(img, tree->children[0], x, y, size/2);
        decompress_img(img, tree->children[1], x, y + size/2, size/2);
        decompress_img(img, tree->children[2], x + size/2, y + size/2, size/2);
        decompress_img(img, tree->children[3], x + size/2, y, size/2);
    } else {
        struct term_node_data *data = (struct term_node_data *) tree->data;
        for (int i = x; i < x + size; ++i)
            for (int j = y; j < y + size; ++j)
                img->matrix[i][j] = data->pixel;
    }
}
