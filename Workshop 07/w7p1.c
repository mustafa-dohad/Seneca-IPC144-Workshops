/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MULTIPLE 5
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10

// Define a structure to represent the game configuration settings
struct GameConfiguration {
    char player_representation;
    int lives;
    int path_length;
    int moves;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
};

int main(void) {
    struct GameConfiguration config;

    int validlives = 0, valid_path_length = 0, validmoves = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &config.player_representation);

    while (!validlives) {
        printf("Set the number of lives: ");
        scanf("%d", &config.lives);
        if (config.lives >= MIN_LIVES && config.lives <= MAX_LIVES) {
            validlives = 1;
            printf("Player configuration set-up is complete\n\n");
        } else
            printf("     Must be between 1 and 10!\n");
    }

    printf("GAME Configuration\n");
    printf("------------------\n");

    while (!valid_path_length) {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &config.path_length);
        if ((config.path_length % MULTIPLE == 0) && (config.path_length >= MIN_PATH_LENGTH && config.path_length <= MAX_PATH_LENGTH)) {
            valid_path_length = 1;
        } else
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
    }

    while (!validmoves) {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &config.moves);
        if (config.moves >= 3 && config.moves <= 26) {
            validmoves = 1;
        } else
            printf("    Value must be between 3 and 26\n");
    }

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!");
    printf("\n");
    int i;
    for (i = 0; i < (config.path_length / MULTIPLE); i++) {
        if (i == 0) {
            printf("   Positions [ %d- %d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &config.bombs[i * 5], &config.bombs[(i * 5) + 1], &config.bombs[(i * 5) + 2], &config.bombs[(i * 5) + 3], &config.bombs[(i * 5) + 4]);
        } else if (i == 1) {
            printf("   Positions [ %d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &config.bombs[i * 5], &config.bombs[(i * 5) + 1], &config.bombs[(i * 5) + 2], &config.bombs[(i * 5) + 3], &config.bombs[(i * 5) + 4]);
        } else {
            printf("   Positions [%d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &config.bombs[i * 5], &config.bombs[(i * 5) + 1], &config.bombs[(i * 5) + 2], &config.bombs[(i * 5) + 3], &config.bombs[(i * 5) + 4]);
        }
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!");
    printf("\n");
    for (i = 0; i < (config.path_length / MULTIPLE); i++) {
        if (i == 0) {
            printf("   Positions [ %d- %d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &config.treasure[i * 5], &config.treasure[(i * 5) + 1], &config.treasure[(i * 5) + 2], &config.treasure[(i * 5) + 3], &config.treasure[(i * 5) + 4]);
        } else if (i == 1) {
            printf("   Positions [ %d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &config.treasure[i * 5], &config.treasure[(i * 5) + 1], &config.treasure[(i * 5) + 2], &config.treasure[(i * 5) + 3], &config.treasure[(i * 5) + 4]);
        } else {
            printf("   Positions [%d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &config.treasure[i * 5], &config.treasure[(i * 5) + 1], &config.treasure[(i * 5) + 2], &config.treasure[(i * 5) + 3], &config.treasure[(i * 5) + 4]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", config.player_representation);
    printf("   Lives      : %d\n", config.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", config.path_length);
    printf("   Bombs      : ");
    for (i = 0; i < config.path_length; i++) {
        printf("%d", config.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < config.path_length; i++) {
        printf("%d", config.treasure[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    return 0;
}
