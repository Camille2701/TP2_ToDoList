#include "headers/liste.h"
#include "menu.c"


int main() {
    menu();
    TaskList* list = create_empty_task_list();
    add_task(list, create_task("Task 1", 5));
    add_task(list, create_task("Task 2", 3));

    print_tasks_in_order(list);


return 0;
}


