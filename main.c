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

// tableau [Chaque ligne = [ chaque case = [valeur -1=X 0=Vide nb=nb, je suis ici, couleur 0=rien 1=bleu 2=rouge 3=vert 4=orange, nb tour]]]

int ***niveau0() {
    int ***tableau = malloc(2 * sizeof(int **));
    for (int i = 0; i < 2; i++){
        tableau[i] = malloc(4 * sizeof(int *));
        for (int j = 0; j < 4; j++){
            tableau[i][j] = malloc(4 * sizeof(int));
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                tableau[i][j][k] = 0;
            }
        }
    }
    tableau[0][0][0] = -1;
    tableau[0][1][2] = 2;
    //tableau[0][1][1] = 1;
    tableau[0][2][1] = 1;
    return tableau;
}

int ***choixDuNiveau(int *abscisses , int *ordonnees , int ***tableau , int *choixNiveauCorrect) {
    int choix;
    printf("Choisissez le niveau entre 0 facile et 30 dificile : \n");
    scanf("%d", &choix);
    switch(choix){
        case 0:
            tableau = niveau0();
            *abscisses = 2;
            *ordonnees = 4;
            *choixNiveauCorrect = 1;
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
            if (tableau[i][j][0] == -1){
                aAfficher = ' ';
            }
            if (tableau[i][j][0] == 0){
                aAfficher = 'X';
            }
            switch (tableau[i][j][2])
            {
                case 1:
                    if (tableau[i][j][1] == 1){
                        printf("\e[7m\033[37m\033[34m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[34m%c\033[0m", aAfficher);
                    }
                    break;
                case 2:
                    if (tableau[i][j][1] == 1){
                        printf("\e[7m\033[37m\033[31m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[31m%c\033[0m", aAfficher);
                    }
                    break;
                case 3:
                    if (tableau[i][j][1] == 1){
                        printf("\e[7m\033[37m\033[32m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[32m%c\033[0m", aAfficher);
                    }
                    break;
                case 4:
                    if (tableau[i][j][1] == 1){
                        printf("\e[7m\033[37m\033[33m%c\033[0m\e[0m", aAfficher);
                    } else {
                        printf("\033[33m%c\033[0m", aAfficher);
                    }
                    break;
                default:
                    if (tableau[i][j][1] == 1){
                        printf("\e[7m\033[37m%c\e[0m", aAfficher);
                    } else {
                        printf("%c", aAfficher);
                    }
                    break;
            }
        }
        printf("\n");
    }
}

int deplacementPossible(char depacement, int ***tableau , int abscisses , int ordonnees) {
    int retour = 0;
    switch (depacement)
    {
        case 'Z':
            for (int i = 0; i < abscisses; i++){
                for (int j = 0; j < ordonnees; j++){
                    if (tableau[i][j][1] == 1){
                        if (i > 0){
                            if (tableau[i-1][j][0] == 0){
                                retour = 1;
                            }
                        }
                    }
                }
            }
            break;
        case 'Q':
            for (int i = 0; i < abscisses; i++){
                for (int j = 0; j < ordonnees; j++){
                    if (tableau[i][j][1] == 1){
                        if (j > 0){
                            if (tableau[i][j-1][0] == 0){
                                retour = 1;
                            }
                        }
                    }
                }
            }
            break;
        case 'S':
            for (int i = 0; i < abscisses; i++){
                for (int j = 0; j < ordonnees; j++){
                    if (tableau[i][j][1] == 1){
                        if (i < abscisses - 1){
                            if (tableau[i+1][j][0] == 0){
                                retour = 1;
                            }
                        }
                    }
                }
            }
            break;
        case 'D':
            for (int i = 0; i < abscisses; i++){
                for (int j = 0; j < ordonnees; j++){
                    if (tableau[i][j][1] == 1){
                        if (j < ordonnees - 1){
                            if (tableau[i][j+1][0] == 0){
                                retour = 1;
                            }
                        }
                    }
                }
            }
            break;
    }
    return retour;
}

void queFaire(int ***tableau , int abscisses , int ordonnees , int *partieFinie) {
    int positionActuelle[2];
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            if (tableau[i][j][1] == 1){
                printf("--- Ligne : %d, Colonne : %d, Couleur : ", i , j);
                switch (tableau[i][j][2])
                {
                    case 1:
                        printf("\033[34mBleu\033[0m");
                        break;
                    case 2:
                        printf("\033[31mRouge\033[0m");
                        break;
                    case 3:
                        printf("\033[32mVert\033[0m");
                        break;
                    case 4:
                        printf("\033[33mOrange\033[0m");
                        break;
                    default:
                        printf("Aucune");
                        break;
                }
                printf(" ---\n");
                positionActuelle[0] = i;
                positionActuelle[1] = j;
            }
        }
    }
    printf("Pour sélectionner une direction (Z, Q, S, D) \n");
    printf("Pour annuler le dernier coup (A) \n");
    printf("Pour effecer la chaine (E) \n");
    printf("Pour sélectionner une autre couleur (B, R, V, O) \n");
    printf("Pour quitter (P) \n");
    int choixValide = 0;
    while (choixValide == 0)
    {
        char choix;
        scanf(" %c", &choix);
        choixValide = 1;
        switch (choix)
        {
            case 'Z':
                printf("Vous avez choisi de vous déplacer vers le haut \n");
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1 && tableau[positionActuelle[0]][positionActuelle[1]][0] <= tableau[positionActuelle[0]-1][positionActuelle[1]][0] && tableau[positionActuelle[0]-1][positionActuelle[1]][0] != 0){
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    tableau[positionActuelle[0]-1][positionActuelle[1]][1] = 1;
                    tableau[positionActuelle[0]-1][positionActuelle[1]][2] = tableau[positionActuelle[0]][positionActuelle[1]][2];
                    tableau[positionActuelle[0]-1][positionActuelle[1]][3] = tableau[positionActuelle[0]][positionActuelle[1]][3] + 1;
                } else {
                    printf("Deplacement impossible \n");
                    choixValide = 0;
                }
                break;
            case 'Q':
                printf("Vous avez choisi de vous déplacer vers la gauche \n");
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1 && tableau[positionActuelle[0]][positionActuelle[1]][0] <= tableau[positionActuelle[0]][positionActuelle[1]-1][0] && tableau[positionActuelle[0]][positionActuelle[1]-1][0] != 0){
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    tableau[positionActuelle[0]][positionActuelle[1]-1][1] = 1;
                    tableau[positionActuelle[0]][positionActuelle[1]-1][2] = tableau[positionActuelle[0]][positionActuelle[1]][2];
                    tableau[positionActuelle[0]][positionActuelle[1]-1][3] = tableau[positionActuelle[0]][positionActuelle[1]][3] + 1;
                } else {
                    printf("Deplacement impossible \n");
                    choixValide = 0;
                }
                break;
            case 'S':
                printf("Vous avez choisi de vous déplacer vers le bas \n");
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1 && tableau[positionActuelle[0]][positionActuelle[1]][0] <= tableau[positionActuelle[0]+1][positionActuelle[1]][0] && tableau[positionActuelle[0]+1][positionActuelle[1]][0] != 0){
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    tableau[positionActuelle[0]+1][positionActuelle[1]][1] = 1;
                    tableau[positionActuelle[0]+1][positionActuelle[1]][2] = tableau[positionActuelle[0]][positionActuelle[1]][2];
                    tableau[positionActuelle[0]+1][positionActuelle[1]][3] = tableau[positionActuelle[0]][positionActuelle[1]][3] + 1;
                } else {
                    printf("Deplacement impossible \n");
                    choixValide = 0;
                }
                break;
            case 'D':
                printf("Vous avez choisi de vous déplacer vers la droite \n");
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1 && tableau[positionActuelle[0]][positionActuelle[1]][0] <= tableau[positionActuelle[0]][positionActuelle[1]+1][0] && tableau[positionActuelle[0]][positionActuelle[1]+1][0] != 0){
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    tableau[positionActuelle[0]][positionActuelle[1]+1][1] = 1;
                    tableau[positionActuelle[0]][positionActuelle[1]+1][2] = tableau[positionActuelle[0]][positionActuelle[1]][2];
                    tableau[positionActuelle[0]][positionActuelle[1]+1][3] = tableau[positionActuelle[0]][positionActuelle[1]][3] + 1;
                } else {
                    printf("Deplacement impossible \n");
                    choixValide = 0;
                }
                break;
            case 'A':
                printf("Vous avez choisi d'annuler le dernier coup \n");
                if (tableau[positionActuelle[0]][positionActuelle[1]][3] == 1){
                    printf("Vous ne pouvez pas annuler ce coup \n");
                    choixValide = 0;
                } else {
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    tableau[positionActuelle[0]][positionActuelle[1]][2] = 0;
                    tableau[positionActuelle[0]][positionActuelle[1]][3] = 0;
                }
                break;
            case 'E':
                printf("Vous avez choisi d'effacer la chaine \n");
                // le faire plus tard
                break;
            case 'B':
                printf("Vous avez choisi de changer de couleur pour bleu \n");
                tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                int dernierePositionCouleur[3]; // de la forme [nombre de coup, abscisses, ordonnees]
                dernierePositionCouleur[0] = 0;
                int couleurTrouve = 0;
                
                for (int i = 0; i<abscisses; i++){
                    for (int j = 0; j<ordonnees; j++) {
                        if (tableau[i][j][2] == 1) {
                            if (tableau[i][j][3] > dernierePositionCouleur[0]){
                                // Je me suis arrêté ici
                            }
                        }
                    }
                }

                break;
            case 'R':
                printf("Vous avez choisi de changer de couleur pour rouge \n");
                break;
            case 'V':
                printf("Vous avez choisi de changer de couleur pour vert \n");
                break;
            case 'O':
                printf("Vous avez choisi de changer de couleur pour orange \n");
                break;
            case 'P':
                printf("Vous avez choisi de quitter \n");
                *partieFinie = 1;
                break;
            default:
                printf("Choix invalide \n");
                choixValide = 0;
                break;
        }
    }
}

int main() {
    int ***tableau;
    int abscisses;
    int ordonnees;
    int choixNiveauCorrect = 0;
    int partieFinie = 0;
    while (choixNiveauCorrect == 0){
        tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect);
    }

    system("clear");
    
    affichage(tableau , abscisses , ordonnees);

    queFaire(tableau , abscisses , ordonnees , &partieFinie);

    return 0;
}