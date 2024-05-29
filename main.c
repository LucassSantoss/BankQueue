#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void add_new_client(t_queue *queue_general, t_queue *queue_priority, char command, char *name) {
    client c;
    strcpy(c.name, name);
    c.type = command;
    if (command == 'g') {
        in(queue_general, c);
    } else {
        in(queue_priority, c);
    }
}

void attend_next_client(t_queue *queue_general, t_queue *queue_priority, 
t_queue *queue_attended, int *attended_priority_in_row) {
    client c;
    if (!is_queue_empty(queue_priority) && *attended_priority_in_row < 3) {
        out(queue_priority, &c);
        (*attended_priority_in_row)++;
    } else if (!is_queue_empty(queue_general)) {
        out(queue_general, &c);
        *attended_priority_in_row = 0;
    } else if (!is_queue_empty(queue_priority)) {
        out(queue_priority, &c);
        *attended_priority_in_row = 1;
    }
    in(queue_attended, c);
}

void print_attended_clients(t_queue *queue_attended) {
    client c;
    while (!is_queue_empty(queue_attended)) {
        out(queue_attended, &c);
        printf("%s\n", c.name);
    }
}

int main() {
    t_queue queue_general, queue_priority, queue_attended;
    init_queue(&queue_general, 100);
    init_queue(&queue_priority, 100);
    init_queue(&queue_attended, 100);
    
    char command;
    char name[50];
    int attended_priority_in_row = 0;
    
    while (1) {
        scanf(" %c", &command);
        if (command == 'f') break;

        if (command == 'g' || command == 'p') {
            scanf(" %s", name);
            add_new_client(&queue_general, &queue_priority, command, name);
        } else if (command == 's') {
            attend_next_client(&queue_general, &queue_priority, &queue_attended, &attended_priority_in_row);
        }
    }

    print_attended_clients(&queue_attended);
   
    destroy_queue(&queue_attended);
    destroy_queue(&queue_general);
    destroy_queue(&queue_priority);

    return 0;
}
