#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

typedef struct {
    char name[50];
    char type;
} client;

typedef struct {
    client clients[MAX];
    int start;
    int end;
    int n;
} t_queue;

void init_queue(t_queue *f);
int is_queue_empty(t_queue *f);
int is_queue_full(t_queue *f);
int in(t_queue *f, client c);
int out(t_queue *f, client *c);
void print_queue(t_queue *f);

#endif
