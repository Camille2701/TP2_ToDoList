#include "headers/liste.h"

TaskList* create_empty_task_list() {
    TaskList* list = (TaskList*)malloc(sizeof(TaskList));
    if (list == NULL) {
        printf("Echec de l'allocation de mémoire\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

Task* create_task(char* nom, int jours) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    if (new_task == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_task->nom = nom;
    new_task->date_creation = time(NULL);
    new_task->statut = EN_ATTENTE;
    new_task->jours_restants = jours;
    new_task->next = NULL;
    return new_task;
}

void add_task(TaskList* list, Task* task) {
    if (list->head == NULL) {
        list->head = task;
    } else {
        Task* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = task;
    }
}

void print_tasks_in_order(TaskList* list) {
    Task* lastPrinted = NULL;
    while (1) {
        Task* smallest = NULL;
        for (Task* task = list->head; task != NULL; task = task->next) {
            if ((lastPrinted == NULL || difftime(task->date_creation, lastPrinted->date_creation) > 0) &&
                (smallest == NULL || difftime(task->date_creation, smallest->date_creation) < 0)) {
                smallest = task;
            }
        }
        if (smallest == NULL) {
            break;
        }
        printf("Task: %s, Date: %s, Status: %d, Days left: %d\n", smallest->nom, ctime(&(smallest->date_creation)), smallest->statut, smallest->jours_restants);
        lastPrinted = smallest;
    }
}
