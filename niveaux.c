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

int ***niveau0(int abscisse, int ordonnee) {
    int*** tableau = creerTableau(abscisse, ordonnee);
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
    printf("Il n'y a pas eu de pb avec le niveau 1");
    return tableau;
}