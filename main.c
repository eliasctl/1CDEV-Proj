// Projet final C SupInfo 2022 - 2023
// Sujet Jeu Cardinal Chains

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <time.h>

// Couleurs pour le terminal
// 1 Bleu "\033[34m"
// 2 Rouge "\033[31m"
// 3 Vert "\033[32m"
// 4 Orange "\033[33m"
// Reset "\033[0m"

int ***niveau0() {
    int ***tableau = malloc(2 * sizeof(int **));
    for (int i = 0; i < 2; i++){
        tableau[i] = malloc(4 * sizeof(int *));
        for (int j = 0; j < 4; j++){
            tableau[i][j] = malloc(3 * sizeof(int));
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 3; k++){
                tableau[i][j][k] = 0;
            }
        }
    }
    tableau[0][0][0] = 1;
    tableau[0][1][2] = 2;
    //tableau[0][1][1] = 1;
    tableau[1][2][1] = 1;
    return tableau;
}

int ***choixDuNiveau(int *abscisses , int *ordonnees , int ***tableau , int *reponse) {
    int choix;
    printf("Choisissez le niveau entre 0 facile et 30 dificile : \n");
    scanf("%d", &choix);
    switch(choix){
        case 0:
            tableau = niveau0();
            *abscisses = 2;
            *ordonnees = 4;
            *reponse = 1;
            return tableau;
            break;
        // faire les autres niveaux
        default:
            printf("Choix invalide \n");
            return NULL;
            break;
    }
}

void affichage(int ***tableau , int abscisses , int ordonnees) {
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            char aAfficher = tableau[i][j][0];
            aAfficher = aAfficher + '0';
            if (tableau[i][j][0] == 0){
                aAfficher = 'X';
            }
            // régler le problème de la couleur de fond
            if (tableau[i][j][1] == 1){
                printf("\e[7m");
            }
            switch (tableau[i][j][2])
            {
                case 1:
                    if (tableau[i][j][1] == 1){
                        printf("\033[37m\033[34m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[34m%c\033[0m", aAfficher);
                    }
                    break;
                case 2:
                    if (tableau[i][j][1] == 1){
                        printf("\033[37m\033[31m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[31m%c\033[0m", aAfficher);
                    }
                    break;
                case 3:
                    if (tableau[i][j][1] == 1){
                        printf("\033[37m\033[32m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[32m%c\033[0m", aAfficher);
                    }
                    break;
                case 4:
                    if (tableau[i][j][1] == 1){
                        printf("\033[37m\033[33m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[33m%c\033[0m", aAfficher);
                    }
                    break;
                default:
                    if (tableau[i][j][1] == 1){
                        printf("\033[37m%c\e[0m", aAfficher);
                    } else {
                        printf("%c", aAfficher);
                    }
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    int ***tableau;
    int abscisses;
    int ordonnees;
    int reponse;
    reponse = 0;
    while (reponse == 0){
        tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &reponse);
    }

    system("clear");
    
    affichage(tableau , abscisses , ordonnees);

    printf("\e[7m Bonjour \e[0m \n Blabla Car \n");
    return 0;
}