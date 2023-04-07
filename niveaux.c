// Ce fichier contient les fonctions qui permettent de choisir le niveau et de charger le tableau correspondant
// Il est appelé par le fichier main.c

int*** creerTableau(int abscisse, int ordonnee) {
    // allocation de la mémoire pour le tableau à 3 dimensions
    int*** tableau = (int***)malloc(abscisse * sizeof(int**));
    for(int i = 0; i < abscisse; i++) {
        tableau[i] = (int**)malloc(ordonnee * sizeof(int*));
        for(int j = 0; j < ordonnee; j++) {
            tableau[i][j] = (int*)malloc(4 * sizeof(int));
            tableau[i][j][0] = 1;
            tableau[i][j][1] = 0;
            tableau[i][j][2] = 0;
            tableau[i][j][3] = 0;
        }
    }
    return tableau;
}

int ***niveau0() {
    int*** tableau = creerTableau(1, 4);
    tableau[0][0][0] = 0;
    tableau[0][0][1] = 1;
    tableau[0][0][2] = 1;
    tableau[0][0][3] = 1;
    return tableau;
}

int ***niveau1() {
    int ***tableau = creerTableau(3, 3);
    // Case de départ
    tableau[2][0][0] = 0;
    tableau[2][0][1] = 1;
    tableau[2][0][2] = 1;
    tableau[2][0][3] = 1;
    // Cases Vides
    tableau[0][0][0] = -1;
    tableau[0][1][0] = -1;
    tableau[2][1][0] = -1;
    tableau[2][2][0] = -1;
    return tableau;
}

int ***niveau2() {
    int ***tableau = creerTableau(3, 3);
    // Case de départ
    tableau[2][2][0] = 0;
    tableau[2][2][1] = 1;
    tableau[2][2][2] = 1;
    tableau[2][2][3] = 1;
    // Cases Vides
    tableau[1][1][0] = -1;
    tableau[2][1][0] = -1;
    return tableau;
}

int ***niveau3() {
    int ***tableau = creerTableau(5, 5);
    // Case de départ
    tableau[2][2][0] = 0;
    tableau[2][2][1] = 1;
    tableau[2][2][2] = 1;
    tableau[2][2][3] = 1;
    // Cases Vides
    tableau[1][1][0] = -1;
    tableau[1][2][0] = -1;
    tableau[1][3][0] = -1;
    tableau[1][4][0] = -1;
    tableau[2][1][0] = -1;
    tableau[3][1][0] = -1;
    tableau[3][2][0] = -1;
    tableau[3][3][0] = -1;
    return tableau;
}

int ***niveau4() {
    int ***tableau = creerTableau(4, 3);
    // Case de départ
    tableau[1][1][0] = 0;
    tableau[1][1][1] = 1;
    tableau[1][1][2] = 1;
    tableau[1][1][3] = 1;
    // Cases Vides
    tableau[2][1][0] = -1;
    tableau[2][2][0] = -1;
    return tableau;
}

int ***niveau5() {
    int ***tableau = creerTableau(5, 5);
    // Case de départ
    tableau[2][2][0] = 0;
    tableau[2][2][1] = 1;
    tableau[2][2][2] = 1;
    tableau[2][2][3] = 1;
    // Cases Vides
    tableau[0][4][0] = -1;
    tableau[1][1][0] = -1;
    tableau[1][2][0] = -1;
    tableau[2][1][0] = -1;
    tableau[2][4][0] = -1;
    tableau[3][1][0] = -1;
    tableau[3][2][0] = -1;
    tableau[3][4][0] = -1;
    tableau[4][4][0] = -1;
    return tableau;
}

int ***niveau6() {
    int ***tableau = creerTableau(2, 2);
    // Case de départ
    tableau[1][0][0] = 0;
    tableau[1][0][1] = 1;
    tableau[1][0][2] = 1;
    tableau[1][0][3] = 1;
    // Cases Vides
    // Case Valeur
    tableau[1][1][0] = 2;
    return tableau;

}

int ***niveau7() {
    int ***tableau = creerTableau(3, 2);
    // Case de départ
    tableau[1][1][0] = 0;
    tableau[1][1][1] = 1;
    tableau[1][1][2] = 1;
    tableau[1][1][3] = 1;
    // Cases Vides
    // Case Valeur
    tableau[2][1][0] = 2;
    return tableau;
}

int ***niveau8() {
    int ***tableau = creerTableau(4, 2);
    // Case de départ
    tableau[3][0][0] = 0;
    tableau[3][0][1] = 1;
    tableau[3][0][2] = 1;
    tableau[3][0][3] = 1;
    // Cases Vides
    tableau[0][1][0] = -1;
    tableau[3][1][0] = -1;
    // Case Valeur
    tableau[0][0][0] = 2;
    return tableau;
}

int ***niveau9() {
    int ***tableau = creerTableau(3, 3);
    // Case de départ
    tableau[1][1][0] = 0;
    tableau[1][1][1] = 1;
    tableau[1][1][2] = 1;
    tableau[1][1][3] = 1;
    // Cases Vides
    // Case Valeur
    tableau[0][0][0] = 2;
    tableau[1][0][0] = 2;
    return tableau;
}

int ***niveau10() {
    int ***tableau = creerTableau(4, 4);
    // Case de départ
    tableau[1][1][0] = 0;
    tableau[1][1][1] = 1;
    tableau[1][1][2] = 1;
    tableau[1][1][3] = 1;
    // Cases Vides
    tableau[2][1][0] = -1;
    // Case Valeur
    tableau[0][2][0] = 3;
    tableau[1][2][0] = 2;
    return tableau;
}

int ***niveau11() {
    int ***tableau = creerTableau(4, 3);
    // Case de départ
    tableau[0][2][0] = 0;
    tableau[0][2][1] = 1;
    tableau[0][2][2] = 1;
    tableau[0][2][3] = 1;
    // Cases Vides
    tableau[0][0][0] = -1;
    tableau[0][1][0] = -1;
    // Case Valeur
    tableau[3][0][0] = 2;
    tableau[3][1][0] = 2;
    tableau[3][2][0] = 3;
    return tableau;
}

int ***niveau12() {
    int ***tableau = creerTableau(4, 3);
    // Case de départ
    tableau[0][2][0] = 0;
    tableau[0][2][1] = 1;
    tableau[0][2][2] = 1;
    tableau[0][2][3] = 1;
    // Cases Vides
    tableau[0][1][0] = -1;
    // Case Valeur
    tableau[0][0][0] = 3;
    tableau[1][0][0] = 3;
    tableau[2][0][0] = 3;
    tableau[3][0][0] = 3;
    tableau[1][1][0] = 2;
    tableau[2][1][0] = 2;
    tableau[3][1][0] = 2;
    tableau[2][2][0] = 2;
    tableau[3][2][0] = 2;
    return tableau;
}

int ***niveau13() {
    int ***tableau = creerTableau(4, 4);
    // Case de départ
    tableau[3][0][0] = 0;
    tableau[3][0][1] = 1;
    tableau[3][0][2] = 1;
    tableau[3][0][3] = 1;
    // Cases Vides
    tableau[0][0][0] = -1;
    tableau[0][1][0] = -1;
    tableau[0][2][0] = -1;
    tableau[1][0][0] = -1;
    tableau[2][0][0] = -1;
    // Case Valeur
    tableau[0][3][0] = 5;
    tableau[1][1][0] = 2;
    tableau[1][2][0] = 2;
    tableau[1][3][0] = 4;
    tableau[2][1][0] = 2;
    tableau[2][2][0] = 2;
    tableau[2][3][0] = 3;
    tableau[3][2][0] = 2;
    tableau[3][3][0] = 2;
    return tableau;
}

int ***niveau14() {
    int ***tableau = creerTableau(5, 5);
    // Case de départ
    tableau[2][1][0] = 0;
    tableau[2][1][1] = 1;
    tableau[2][1][2] = 1;
    tableau[2][1][3] = 1;
    // Cases Vides
    tableau[1][1][0] = -1;
    tableau[3][1][0] = -1;
    // Case Valeur
    tableau[0][3][0] = 3;
    tableau[0][4][0] = 4;
    tableau[1][3][0] = 3;
    tableau[1][4][0] = 5;
    tableau[2][3][0] = 3;
    tableau[2][4][0] = 3;
    tableau[3][4][0] = 3;
    tableau[4][3][0] = 2;
    tableau[4][4][0] = 2;
    return tableau;
}

int ***niveau15() {
    int ***tableau = creerTableau(5, 6);
    // Case de départ
    tableau[1][5][0] = 0;
    tableau[1][5][1] = 1;
    tableau[1][5][2] = 1;
    tableau[1][5][3] = 1;
    // Cases Vides
    tableau[0][0][0] = -1;
    tableau[0][5][0] = -1;
    tableau[2][0][0] = -1;
    tableau[2][4][0] = -1;
    tableau[2][5][0] = -1;
    tableau[3][0][0] = -1;
    tableau[3][2][0] = -1;
    tableau[3][4][0] = -1;
    tableau[3][5][0] = -1;
    tableau[4][0][0] = -1;
    tableau[4][4][0] = -1;
    tableau[4][5][0] = -1;
    // Case Valeur
    tableau[0][1][0] = 7;
    tableau[0][2][0] = 6;
    tableau[0][3][0] = 3;
    tableau[0][4][0] = 2;
    tableau[1][0][0] = 9;
    tableau[1][1][0] = 8;
    tableau[1][2][0] = 5;
    tableau[1][3][0] = 4;
    tableau[2][1][0] = 4;
    tableau[2][2][0] = 4;
    tableau[2][3][0] = 4;
    tableau[3][1][0] = 4;
    tableau[3][3][0] = 4;
    tableau[4][1][0] = 4;
    tableau[4][2][0] = 4;
    tableau[4][3][0] = 4;
    return tableau;
}

int ***niveau16() {
    int ***tableau = creerTableau(6, 6);
    // Case de départ
    tableau[0][4][0] = 0;
    tableau[0][4][1] = 1;
    tableau[0][4][2] = 1;
    tableau[0][4][3] = 1;
    // Cases Vides
    tableau[0][0][0] = -1;
    tableau[0][1][0] = -1;
    tableau[0][2][0] = -1;
    tableau[0][3][0] = -1;
    tableau[0][5][0] = -1;
    tableau[1][5][0] = -1;
    tableau[3][2][0] = -1;
    tableau[3][3][0] = -1;
    tableau[3][4][0] = -1;
    tableau[3][5][0] = -1;
    tableau[4][5][0] = -1;
    tableau[5][5][0] = -1;
    // Case Valeur
    tableau[2][4][0] = 8;
    tableau[2][5][0] = 9;
    return tableau;
}

int ***niveau17() {
    int ***tableau = creerTableau(4, 4);
    // Case de départ
    tableau[2][1][0] = 0;
    tableau[2][1][1] = 1;
    tableau[2][1][2] = 1;
    tableau[2][1][3] = 1;
    // Cases Vides
    tableau[0][0][0] = -1;
    tableau[3][2][0] = -1;
    tableau[3][3][0] = -1;
    // Case Valeur
    tableau[0][1][0] = 9;
    tableau[0][2][0] = 8;
    tableau[0][3][0] = 7;
    tableau[1][0][0] = 4;
    tableau[1][1][0] = 4;
    tableau[1][2][0] = 4;
    tableau[1][3][0] = 6;
    tableau[2][0][0] = 4;
    tableau[2][2][0] = 4;
    tableau[2][3][0] = 5;
    tableau[3][0][0] = 4;
    tableau[3][1][0] = 4;
    return tableau;
}

//niveau 18
// 222
// 222
//X129
// 228
// 227