// Created by Camille VEILLARD on 27/10/2023

#ifndef liste_H
#define liste_H

//Insérer les bibliothèques nécessaires
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Insérer les nouveaux types
typedef enum {EN_ATTENTE, EN_COURS, TERMINEE} Statut;

typedef struct Task {
    char* nom;
    time_t date_creation;
    Statut statut;
    int jours_restants;
    struct Task* next;
} Task;

typedef struct TaskList {
    Task* head;
} TaskList;

//Insérer les autres prototypes ici 

#endif