// Projet final C SupInfo 2022 - 2023
// Sujet Jeu Cardinal Chains

#include <stdio.h>
#include <stdlib.h>
#include "niveaux.c"

// Couleurs pour le terminal
// 1 Bleu "\033[34m"
// 2 Rouge "\033[31m"
// 3 Vert "\033[32m"
// 4 Orange "\033[33m"
// Reset "\033[0m"

// tableau [Chaque ligne = [ chaque case = [valeur -1=vide 0=X nb=nb, je suis ici, couleur 0=rien 1=bleu 2=rouge 3=vert 4=orange, nb tour]]]

int ***choixDuNiveau(int *abscisses , int *ordonnees , int ***tableau , int *choixNiveauCorrect, int *niveau) {
    int choix;
    if (*niveau == -1){
        printf("Choisissez le niveau entre 0 facile et 30 dificile : \n");
        scanf("%d", &choix);
        printf("Vous avez choisi le niveau %d \n", choix);
        *niveau = choix;
    } else {
        choix = *niveau;
    }
    switch(choix){
        case 0:
            tableau = niveau0();
            *abscisses = 1;
            *ordonnees = 4;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 1:
            tableau = niveau1();
            *abscisses = 3;
            *ordonnees = 3;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 2:
            tableau = niveau2();
            *abscisses = 3;
            *ordonnees = 3;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 3:
            tableau = niveau3();
            *abscisses = 5;
            *ordonnees = 5;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 4:
            tableau = niveau4();
            *abscisses = 4;
            *ordonnees = 3;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 5:
            tableau = niveau5();
            *abscisses = 5;
            *ordonnees = 5;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 6:
            tableau = niveau6();
            *abscisses = 2;
            *ordonnees = 2;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 7:
            tableau = niveau7();
            *abscisses = 3;
            *ordonnees = 2;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 8:
            tableau = niveau8();
            *abscisses = 4;
            *ordonnees = 2;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 9:
            tableau = niveau9();
            *abscisses = 3;
            *ordonnees = 3;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 10:
            tableau = niveau10();
            *abscisses = 4;
            *ordonnees = 3;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 11:
            tableau = niveau11();
            *abscisses = 4;
            *ordonnees = 3;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 12:
            tableau = niveau12();
            *abscisses = 4;
            *ordonnees = 3;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 13:
            tableau = niveau13();
            *abscisses = 4;
            *ordonnees = 4;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 14:
            tableau = niveau14();
            *abscisses = 5;
            *ordonnees = 5;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 15:
            tableau = niveau15();
            *abscisses = 5;
            *ordonnees = 6;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 16:
            tableau = niveau16();
            *abscisses = 6;
            *ordonnees = 6;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        case 17:
            tableau = niveau17();
            *abscisses = 4;
            *ordonnees = 4;
            *choixNiveauCorrect = 1;
            return tableau;
            break;
        default:
            printf("Choix invalide \n");
            *choixNiveauCorrect = 0;
            *niveau = -1;
            return 0;
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
            printf(" ");
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
                            if (tableau[i-1][j][0] > 0 && tableau[i-1][j][0] >= tableau[i][j][0] && tableau[i-1][j][2] == 0){
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
                            if (tableau[i][j-1][0] > 0 && tableau[i][j-1][0] >= tableau[i][j][0] && tableau[i][j-1][2] == 0){
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
                            if (tableau[i+1][j][0] > 0 && tableau[i+1][j][0] >= tableau[i][j][0] && tableau[i+1][j][2] == 0){
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
                        if (j < (ordonnees - 1)){
                            if (tableau[i][j+1][0] > 0 && tableau[i][j+1][0] >= tableau[i][j][0] && tableau[i][j+1][2] == 0){
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

void dernierePositionCouleur(int ***tableau , int abscisses , int ordonnees , int couleur) {
    int nbCoups = 0;
    int coordonnees[2];
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            if (tableau[i][j][2] == couleur && tableau[i][j][3] > nbCoups){
                nbCoups = tableau[i][j][3];
                coordonnees[0] = i;
                coordonnees[1] = j;
            }
        }
    }
    tableau[coordonnees[0]][coordonnees[1]][1] = 1;
}

int couleurEstPresente(int ***tableau , int abscisses , int ordonnees , int couleur) {
    int retour = 0;
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            if (tableau[i][j][2] == couleur){
                retour = 1;
            }
        }
    }
    return retour;
}

int partieEstFinie(int ***tableau , int abscisses , int ordonnees, int *partieFinie) {
    int retour = 1;
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            if (tableau[i][j][0] > 0){
                if (tableau[i][j][2] == 0){
                    retour = 0;
                }
            }
        }
    }
    *partieFinie = retour;
    return retour;
}

void queFaire(int ***tableau , int abscisses , int ordonnees , int *partieFinie , int niveau) {
    int positionActuelle[2];
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            if (tableau[i][j][1] == 1){
                printf("--- Niveau : %d, Ligne : %d, Colonne : %d, Couleur : ", niveau,  i , j);
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
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1){
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
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1){
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
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1){
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
                if (deplacementPossible(choix, tableau, abscisses, ordonnees) == 1){
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
                    int couleur = tableau[positionActuelle[0]][positionActuelle[1]][2];
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    tableau[positionActuelle[0]][positionActuelle[1]][2] = 0;
                    tableau[positionActuelle[0]][positionActuelle[1]][3] = 0;
                    dernierePositionCouleur(tableau, abscisses, ordonnees, couleur);
                }
                break;
            case 'E':
                printf("Vous avez choisi d'effacer la chaine \n");
                if (tableau[positionActuelle[0]][positionActuelle[1]][3] == 1){
                    printf("Cette chaine est déjà vide \n");
                    choixValide = 0;
                } else {
                    int couleur = tableau[positionActuelle[0]][positionActuelle[1]][2];
                    for (int i = 0; i < abscisses; i++){
                        for (int j = 0; j < ordonnees; j++){
                            if (tableau[i][j][3] != 1){
                                if (tableau[i][j][2] == couleur){
                                    tableau[i][j][1] = 0;
                                    tableau[i][j][2] = 0;
                                    tableau[i][j][3] = 0;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < abscisses; i++){
                        for (int j = 0; j < ordonnees; j++){
                            if (tableau[i][j][3] == 1){
                                if (tableau[i][j][2] == couleur){
                                    tableau[i][j][1] = 1;
                                }
                            }
                        }
                    }
                }
                break;
            case 'B':
                printf("Vous avez choisi de changer de couleur pour bleu \n");
                if (couleurEstPresente(tableau, abscisses, ordonnees, 1) != 1){
                    printf("La couleur n'est pas présente \n");
                    choixValide =0;
                } else {
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    dernierePositionCouleur(tableau, abscisses, ordonnees, 1);
                }

                break;
            case 'R':
                printf("Vous avez choisi de changer de couleur pour rouge \n");
                if (couleurEstPresente(tableau, abscisses, ordonnees, 2) != 1){
                    printf("La couleur rouge n'est pas présente \n");
                    choixValide = 0;
                } else {
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    dernierePositionCouleur(tableau, abscisses, ordonnees, 2);
                }
                break;
            case 'V':
                printf("Vous avez choisi de changer de couleur pour vert \n");
                if (couleurEstPresente(tableau, abscisses, ordonnees, 3) != 1){
                    printf("La couleur verte n'est pas présente \n");
                    choixValide = 0;
                } else {
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    dernierePositionCouleur(tableau, abscisses, ordonnees, 3);
                }
                break;
            case 'O':
                printf("Vous avez choisi de changer de couleur pour orange \n");
                if (couleurEstPresente(tableau, abscisses, ordonnees, 4) != 1){
                    printf("La couleur orange n'est pas présente \n");
                    choixValide = 0;
                } else {
                    tableau[positionActuelle[0]][positionActuelle[1]][1] = 0;
                    dernierePositionCouleur(tableau, abscisses, ordonnees, 4);
                }
                break;
            case 'P':
                printf("Vous avez choisi de quitter le niveau \n");
                *partieFinie = 2;
                break;
            default:
                printf("Choix invalide \n");
                choixValide = 0;
                break;
        }
    }
}

void explicationDuJeu(){
    system("clear");
    printf("Le but du jeu est de relier remplir de couleur le plateur \n");
    printf("Pour cela vous vous déplacez sur le plateau avec une couleur et chaque case prends la couleur que vous avez. \n");
    printf("Vous pouvez déplacer sur une case de la même valeur que la votre ou une valeur plus grande que la votre. \n");
    printf("Vous ne pouvez pas repasser par une case. \n");
    printf("Vous pouvez vous déplacer avec les touches Z Q S D \n");
    printf("Vous pouvez annuler le dernier coup en appuyant sur A \n");
    printf("Vous pouvez effacer une chaine de pions en appuyant sur E \n");
    printf("Vous pouvez changer de couleur en appuyant sur B pour bleu, R pour rouge, V pour vert, O pour orange \n");
    printf("Vous pouvez choisir de commencer à partir du niveau que vous souhaitez 0 étant le premier niveau et 30 le dernier \n");
    printf("Appuyez sur [entrer] pour continuer ! \n");
}

int choixApresPartie(){
    int choix;
    int choixValide = 0;
    while (choixValide == 0){
        printf("Voulez vous recommencer le niveau ? (1) \n");
        printf("Voulez-vous aller au niveau suivant ? (2) \n");
        printf("Voulez-vous choisir un autre niveau ? (3) \n");
        printf("Voulez-vous quittez le jeu ? (4) \n");
        scanf("%d", &choix);
        switch (choix)
        {
            case 1:
                printf("Vous avez choisi de recommencer le niveau \n");
                choixValide = 1;
                break;
            case 2:
                printf("Vous avez choisi d'aller au niveau suivant \n");
                choixValide = 1;
                break;
            case 3:
                printf("Vous avez choisi de choisir un autre niveau \n");
                choixValide = 1;
                break;
            case 4:
                printf("Vous avez choisi de quitter le jeu \n");
                choixValide = 1;
                break;
            default:
                printf("Choix invalide \n");
                choixValide = 0;
                break;
        }
    }
    return choix;
}

int effacerTableau(int ***tableau, int abscisses, int ordonnees){
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            free(tableau[i][j]);
        }
        free(tableau[i]);
    }
    return 0;
}

int effacerPositionActuelle(int ***tableau, int abscisses, int ordonnees){
    for (int i = 0; i < abscisses; i++){
        for (int j = 0; j < ordonnees; j++){
            tableau[i][j][1] = 0;
        }
    }
    return 0;
}

int main() {
    system("clear");

    int ***tableau;
    int abscisses;
    int ordonnees;
    int niveau = -1;
    int choixNiveauCorrect = 0;
    int partieFinie = 0; // partie fini  0=non 1=gagnée 2=quité
    int jeuFini = 0; // jeu fini 0=non 1=oui
    int valeurChoixApresPartie = 0;
    while (choixNiveauCorrect == 0){
        explicationDuJeu();
        getchar();
        system("clear");
        tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect, &niveau);
    }

    while (jeuFini == 0)
    {
        while (partieFinie == 0){
            system("clear");
            affichage(tableau, abscisses, ordonnees);
            queFaire(tableau, abscisses, ordonnees, &partieFinie, niveau);
            if (partieFinie == 0){
                partieEstFinie(tableau, abscisses, ordonnees, &partieFinie);
            }
        }
        effacerPositionActuelle(tableau, abscisses, ordonnees);
        system("clear");

        if (partieFinie == 1){
            affichage(tableau, abscisses, ordonnees);
            printf("Bravo vous avez gagné au niveau %d 🎉\n", niveau);
            effacerTableau(tableau, abscisses, ordonnees);
            valeurChoixApresPartie =  choixApresPartie();
            switch (valeurChoixApresPartie)
            {
            case 1:
                tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect, &niveau);
                break;
            case 2:
                niveau++;
                tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect, &niveau);
                break;
            case 3:
                niveau = -1;
                tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect, &niveau);
                break;
            case 4:
                jeuFini = 1;
                break;
            }
        } else {
            printf("Vous avez quité le niveau %d\n", niveau);
            effacerTableau(tableau, abscisses, ordonnees);
            valeurChoixApresPartie =  choixApresPartie();
            switch (valeurChoixApresPartie)
            {
            case 1:
                tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect, &niveau);
                break;
            case 2:
                niveau++;
                tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect, &niveau);
                break;
            case 3:
                niveau = -1;
                tableau = choixDuNiveau(&abscisses , &ordonnees , tableau , &choixNiveauCorrect, &niveau);
                break;
            case 4:
                jeuFini = 1;
                break;
            }
        }
        partieFinie = 0;
    }
    return 0;
}

// max booblil | prète moi ta meuf