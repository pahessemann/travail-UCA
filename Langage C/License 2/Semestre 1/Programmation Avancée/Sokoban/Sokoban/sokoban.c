#include <stdio.h>
#include <stdlib.h>
#define NIVEAU_HAUTEUR 20
#define NIVEAU_LARGEUR 20


// Structure de données pour représenter l'état du jeu
struct game_state {
    int player_x; // Position en x du chariot
    int player_y; // Position en y du chariot
    int** board; // Plateau de jeu
    int board_height; // Hauteur du plateau de jeu
    int board_width; // Largeur du plateau de jeu
};

// déclarez un pointeur sur un pointeur d'entiers comme le type de retour de la fonction d'allocation
int** allouer_tableau_2d(int n, int m)
{
    int** tableau;
    tableau = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        tableau[i] = (int*)malloc(m * sizeof(int));
    }
    return tableau;
}


void liberer_tableau_2d(int** tableau, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(tableau[i]);
    }

    free(tableau);
}

void afficher_tableau_2d(int** tableau, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
}



// Fonction pour gérer les entrées du joueur et mettre à jour l'état du jeu
void deplacement(struct game_state* state) {
    char input;

    // Lire l'entrée du joueur
    input = getchar();

    // Mettre à jour la position du chariot en fonction de l'entrée du joueur
    switch (input) {
    case 'w':
        // Vérifier si le déplacement est valide avant de le mettre à jour
        if (state->player_y > 0 && state->board[state->player_y - 1][state->player_x] != 1) {
            state->player_y--;
        }
        break;
    case 'a':
        if (state->player_x > 0 && state->board[state->player_y][state->player_x - 1] != 1) {
            state->player_x--;
        }
        break;
    case 's':
        if (state->player_y < state->board_height - 1 && state->board[state->player_y + 1][state->player_x] != 1) {
            state->player_y++;
        }
        break;
    case 'd':
        if (state->player_x < state->board_width - 1 && state->board[state->player_y][state->player_x + 1] != 1) {
            state->player_x++;
        }
        break;
    }
}

int check_win(struct game_state* state) 
{
    // Parcourez le tableau et vérifiez si toutes les boîtes sont placées sur des cibles
    for (int y = 0; y < state->board_height; y++) {
        for (int x = 0; x < state->board_width; x++) {
            if (state->board[y][x] == 4) {
                // Si nous trouvons une boîte, vérifions si elle est adjacente à une cible
                if (y > 0 && state->board[y - 1][x] != 3) {
                    return 0;
                }
                if (y < state->board_height - 1 && state->board[y + 1][x] != 3) {
                    return 0;
                }
                if (x > 0 && state->board[y][x - 1] != 3) {
                    return 0;
                }
                if (x < state->board_width - 1 && state->board[y][x + 1] != 3) {
                    return 0;
                }
            }
        }
    }

    // Si nous arrivons ici, c'est que toutes les boîtes sont sur des cibles, donc le joueur a gagné
    return 1;
}



int main() {
    // déclarez un pointeur sur un pointeur d'entiers
    int** tableau;
    // définissez la taille du tableau
    int n = 3;
    int m = 4;

    // utilisez les fonctions pour allouer et libérer le tableau
    tableau = allouer_tableau_2d(n, m);

    // utilisez le tableau comme vous le souhaitez
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tableau[i][j] = i * j;
        }
    }

    // utilisez la fonction d'affichage pour afficher le contenu du tableau
    afficher_tableau_2d(tableau, n, m);






    // Ouvrez le fichier contenant le niveau
    FILE* level_file = fopen("level.txt", "r");

    // Créez une structure pour stocker l'état du jeu
    struct game_state state;

    // Chargez le niveau à partir du fichier
    load_level(&state, level_file);

    // Fermez le fichier une fois que nous avons terminé
    fclose(level_file);

    // Boucle principale du jeu
    while (1) {
        // Affichez l'état du jeu
        display_game(&state);

        // Gérez les entrées du joueur
        deplacement(&state);
        //handle_input(&state);

        // Vérifiez si le joueur a gagné
        if (check_win(&state)) {
            printf("Vous avez gagné !\n");
            break;
        }
    }

    // Libérez le tableau de jeu une fois que le jeu est terminé
    liberer_tableau_2d(state.board, state.board_height);

    liberer_tableau_2d(tableau, n);

    return 0

}