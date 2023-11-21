/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

struct GameBoard
{
    char board[MAX_PATH_LENGTH];
};

struct GameSetting
{
    int path_length;
    int moves;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
};

struct Player
{
    char representation;
    int lives;
    int treasurecount;
};

int main(void)
{
    int i;
    struct Player player;
    player.representation = ' '; // Initialize with a space character
    player.lives = 0;
    player.treasurecount = 0;

    struct GameSetting settings;
    settings.path_length = 0;
    settings.moves = 0;

    struct GameBoard game;
    // Initialize the game board with dashes
    for (i = 0; i < MAX_PATH_LENGTH; i++)
    {
        game.board[i] = '-';
    }

    int validlives = 0, valid_path_length = 0, validmoves = 0, nextmove, validnextmove = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.representation);
    while (!validlives)
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives >= MIN_LIVES && player.lives <= MAX_LIVES)
        {
            validlives = 1;
            printf("Player configuration set-up is complete\n\n");
        }
        else
            printf("     Must be between 1 and 10!\n");
    }
    printf("GAME Configuration\n");
    printf("------------------\n");
    while (!valid_path_length)
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &settings.path_length);
        if ((settings.path_length % MULTIPLE == 0) && (settings.path_length >= MIN_PATH_LENGTH && settings.path_length <= MAX_PATH_LENGTH))
        {
            valid_path_length = 1;
        }
        else
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
    }

    // Initialize the board with dashes
    for (i = 0; i < settings.path_length; i++)
    {
        game.board[i] = '-';
    }

    while (!validmoves)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &settings.moves);
        if (settings.moves >= 3 && settings.moves <= 15)
        {
            validmoves = 1;
        }
        else
            printf("    Value must be between 3 and 15\n");
    }
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!");
    printf("\n");

    for (i = 0; i < (settings.path_length / MULTIPLE); i++)
    {
        if (i == 0)
        {
            printf("   Positions [ %d- %d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &settings.bombs[i * 5], &settings.bombs[(i * 5) + 1], &settings.bombs[(i * 5) + 2], &settings.bombs[(i * 5) + 3], &settings.bombs[(i * 5) + 4]);
        }
        else if (i == 1)
        {
            printf("   Positions [ %d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &settings.bombs[i * 5], &settings.bombs[(i * 5) + 1], &settings.bombs[(i * 5) + 2], &settings.bombs[(i * 5) + 3], &settings.bombs[(i * 5) + 4]);
        }
        else
        {
            printf("   Positions [%d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &settings.bombs[i * 5], &settings.bombs[(i * 5) + 1], &settings.bombs[(i * 5) + 2], &settings.bombs[(i * 5) + 3], &settings.bombs[(i * 5) + 4]);
        }
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!");
    printf("\n");
    for (i = 0; i < (settings.path_length / MULTIPLE); i++)
    {
        if (i == 0)
        {
            printf("   Positions [ %d- %d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &settings.treasure[i * 5], &settings.treasure[(i * 5) + 1], &settings.treasure[(i * 5) + 2], &settings.treasure[(i * 5) + 3], &settings.treasure[(i * 5) + 4]);
        }
        else if (i == 1)
        {
            printf("   Positions [ %d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &settings.treasure[i * 5], &settings.treasure[(i * 5) + 1], &settings.treasure[(i * 5) + 2], &settings.treasure[(i * 5) + 3], &settings.treasure[(i * 5) + 4]);
        }
        else
        {
            printf("   Positions [%d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &settings.treasure[i * 5], &settings.treasure[(i * 5) + 1], &settings.treasure[(i * 5) + 2], &settings.treasure[(i * 5) + 3], &settings.treasure[(i * 5) + 4]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.representation);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", settings.path_length);
    printf("   Bombs      : ");
    for (i = 0; i < settings.path_length; i++)
    {
        printf("%d", settings.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < settings.path_length; i++)
    {
        printf("%d", settings.treasure[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    validlives = 0;
    validmoves = 0;
    printf("  ");
    for (i = 0; i < settings.path_length; i++)
    {
        printf("%c", game.board[i]);
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= settings.path_length; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", (i / 10));
        }
        else
            printf("|");
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= settings.path_length; i++)
    {
        if (i % 10 == 0)
        {
            printf("0");
        }
        else
            printf("%d", (i % 10));
    }

    // Main game loop
    while (player.lives > 0 && settings.moves > 0)
    {
        if (settings.moves >= 10)
        {
            printf("\n+---------------------------------------------------+\n");
            printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d", player.lives, player.treasurecount, settings.moves);
            printf("\n+---------------------------------------------------+\n");
        }
        else{
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d", player.lives, player.treasurecount, settings.moves);
        printf("\n+---------------------------------------------------+\n");}

        validnextmove = 0;
        while (!validnextmove)
        {
            printf("Next Move [1-%d]: ", settings.path_length);
            scanf("%d", &nextmove);
            if (nextmove < 1 || nextmove > settings.path_length)
            {
                printf("  Out of Range!!!\n");
            }
            else
                validnextmove = 1;
        }
        printf("\n");
        if (game.board[nextmove - 1] != '-')
        {
            printf("===============> Dope! You've been here before!\n");
            settings.moves += 1;
        }
        else if (settings.bombs[nextmove - 1] == 1 && settings.treasure[nextmove - 1] == 1)
        {
            game.board[nextmove - 1] = '&';
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            player.treasurecount++;
            player.lives--;
            if (player.lives == 0)
            {
                printf("\nNo more LIVES remaining!\n");
            }
        }
        else if (settings.bombs[nextmove - 1] == 1)
        {
            game.board[nextmove - 1] = '!';
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            player.lives--;
            if (player.lives == 0)
            {
                printf("\nNo more LIVES remaining!\n");
            }
        }
        else if (settings.treasure[nextmove - 1] == 1)
        {
            game.board[nextmove - 1] = '$';
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            player.treasurecount++;
        }
        else if (settings.bombs[nextmove - 1] == 0 && settings.treasure[nextmove - 1] == 0)
        {
            game.board[nextmove - 1] = '.';
            printf("===============> [.] ...Nothing found here... [.]\n");
        }

        settings.moves--;
        printf("\n  ");
        for (i = 0; i < settings.path_length; i++)
        {
            if ((i + 1) == nextmove)
            {
                printf("V");
                break;
            }
            else
            printf(" ");
        }
        printf("\n  ");
        for (i = 0; i < settings.path_length; i++)
        {
            printf("%c", game.board[i]);
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= settings.path_length; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (i / 10));
            }
            else
                printf("|");
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= settings.path_length; i++)
        {
            if (i % 10 == 0)
            {
                printf("0");
            }
            else
                printf("%d", (i % 10));
        }
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d", player.lives, player.treasurecount, settings.moves);
    printf("\n+---------------------------------------------------+\n");
    printf("\n##################\n");
    printf("#   Game over!   #");
    printf("\n##################\n\n");
    printf("You should play again and try to beat your score!\n\n");
    return 0;
}
