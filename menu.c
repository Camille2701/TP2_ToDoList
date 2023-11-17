#include "headers/liste.h"

int menu() {
    int choix;
    TaskList* list;

    do {
        // Afficher le menu
        printf("Menu:\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher les taches d'une liste\n");
        printf("3. Chercher une tache terminee\n");
        printf("4. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        // Effectuer l'action correspondante au choix de l'utilisateur
        switch (choix) {
            case 1:
                printf("Vous avez choisi d'ajouter une tache.\n");
                char task_name[50];
                printf("Entrez le nom de la tache : ");
                scanf("%49s", task_name);  // Lire le nom de la tâche de l'utilisateur

                int task_days;
                printf("Entrez le nombre de jours pour la tache : ");
                scanf("%d", &task_days);  // Lire le nombre de jours de l'utilisateur

                printf("Tache ajoutee avec succes! Voulez vous afficher les taches ?\n");
                printf("1. Oui\n");
                printf("2. Non\n");
                printf("Choisissez une option : ");
                int choix2;
                scanf("%d", &choix2);
                if (choix2 == 1) {
                    print_tasks_in_order(list);
                }

                add_task(list, create_task(task_name, task_days));
                break;
            case 2:
                printf("Vous avez choisi l'action 2.\n");
                print_tasks_in_order(list);
                break;
            case 3:
                printf("Vous avez choisi l'action 3.\n");
                // Ajouter le code pour l'action 3 ici
                break;
            case 4:
                printf("Au revoir!\n");
                break;
            default:
                printf("Option invalide. Veuillez choisir une option valide.\n");
                break;
        }
    } while (choix != 4);

    return 0;
}

