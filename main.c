#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main() {
    t_queue queue_general, queue_priority, queue_attended;
    init_queue(&queue_general);
    init_queue(&queue_priority);
    init_queue(&queue_attended);
    
    char command;
    char name[50];
    int attended_priority_in_row = 0;
    
    while (1) {
        scanf(" %c", &command);
        if (command == 'f') break;

        if (command == 'g' || command == 'p') {
            scanf(" %s", name);
            client c;
            strcpy(c.name, name);
            c.type = command;
            if (command == 'g') {
                in(&queue_general, c);
            } else {
                in(&queue_priority, c);
            }
        } else if (command == 's') {
            client c;
            if (!is_queue_empty(&queue_priority) && attended_priority_in_row < 3) {
                out(&queue_priority, &c);
                attended_priority_in_row++;
            } else if (!is_queue_empty(&queue_general)) {
                out(&queue_general, &c);
                attended_priority_in_row = 0;
            } else if (!is_queue_empty(&queue_priority)) {
                out(&queue_priority, &c);
                attended_priority_in_row = 1;
            }
            in(&queue_attended, c);
        }
    }

    client c;
    while (!is_queue_empty(&queue_attended)) {
        out(&queue_attended, &c);
        printf("%s\n", c.name);
    }

    return 0;
}
