#include "headers/liste.h"

TaskList* create_empty_task_list() {
    TaskList* list = (TaskList*)malloc(sizeof(TaskList));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}
