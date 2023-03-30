// Projet final C SupInfo 2022 - 2023
// Sujet Jeu Cardinal Chains

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <time.h>

//Couleurs pour le terminal
// Bleu "\033[34m"
// Rouge "\033[31m"
// Vert "\033[32m"
// Orange "\033[33m"
// Reset "\033[0m"

int ***niveau0(){
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
    return tableau;
}

void choixDuNiveau(int *abscisses , int *ordonnees , int ***tableau , int *reponse) {
    int choix;
    printf("Choisissez le niveau entre 0 facile et 30 dificile : \n");
    printf("\n");
    scanf("%d", &choix);
    switch(choix){
        case 0:
            ***tableau = niveau0();
            break;
        // faire les autres niveaux
        default:
            printf("Choix invalide \n");
            *reponse = 0;
            break;
    }

}

int main() {
    int ***tableau;
    int abscisses;
    int ordonnees;
    int reponse;
    reponse = 1;
    choixDuNiveau(&abscisses, &ordonnees, &tableau, &reponse);
    if (reponse == 1){
        printf("Vous avez choisi le niveau 0 \n");
    }

    printf("%d\n", tableau[0][0][0]);
}