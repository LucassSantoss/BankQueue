#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void init_queue(t_queue *f, int size) {
    f->clients = (client*) malloc(sizeof(client)*size);
    f->start = 0;
    f->end = 0;
    f->n = 0;
    f->size = size;
}

int is_queue_empty(t_queue *f) {
    return f->n == 0;
}

int is_queue_full(t_queue *f) {
    return f->n == f->size;
}

int in(t_queue *f, client c) {
    if (is_queue_full(f)) return 0;
    f->clients[f->end] = c;
    f->end = (f->end + 1) % f->size;
    f->n++;
    return 1;
}

int out(t_queue *f, client *c) {
    if (is_queue_empty(f)) return 0;
    *c = f->clients[f->start];
    f->start = (f->start + 1) % f->size;
    f->n--;
    return 1;
}

void print_queue(t_queue *f) {
    int i = f->start;
    for (int count = 0; count < f->n; count++) {
        printf("%s\n", f->clients[i].name);
        i = (i + 1) % f->size;
    }
}

void destroy_queue(t_queue *f) {
	free(f->clients);
}