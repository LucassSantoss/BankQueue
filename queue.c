#include "queue.h"
#include <stdio.h>
#include <string.h>

void init_queue(t_queue *f) {
    f->start = 0;
    f->end = 0;
    f->n = 0;
}

int is_queue_empty(t_queue *f) {
    return f->n == 0;
}

int is_queue_full(t_queue *f) {
    return f->n == MAX;
}

int in(t_queue *f, client c) {
    if (is_queue_full(f)) return 0;
    f->clients[f->end] = c;
    f->end = (f->end + 1) % MAX;
    f->n++;
    return 1;
}

int out(t_queue *f, client *c) {
    if (is_queue_empty(f)) return 0;
    *c = f->clients[f->start];
    f->start = (f->start + 1) % MAX;
    f->n--;
    return 1;
}

void print_queue(t_queue *f) {
    int i = f->start;
    for (int count = 0; count < f->n; count++) {
        printf("%s\n", f->clients[i].name);
        i = (i + 1) % MAX;
    }
}
