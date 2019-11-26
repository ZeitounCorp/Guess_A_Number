/**
 * Created By: Lenny Zeitoun
 * Language Used: C
 * IDLE: CLion
 * Date: 27/11/19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int run();
int gameSetup();
int pRound();

// Computer thinks of a number;
int CGuess;
int nbOfGuesses = 0;
int nbOfTrialsAvailable;
int wantToPlay;
char name[128];
int gamerGuess;

int main()
{
    srand(time(NULL));
    run();
    return 0;
}

int run()
{
    printf("\033[1;34m"); // blue bold color
    printf("<============ Welcome to Guess a Number ============>\n");
    printf("<=======   Brought to you wth <3 by @Zcorp   =======>\n");
    printf("<=======   1: We'll ask if you want to play  =======>\n");
    printf("<=======                                     =======>\n");
    printf("<=======   2: We'll ask your name            =======>\n");
    printf("<=======                                     =======>\n");
    printf("<=======   3: We'll ask your age             =======>\n");
    printf("<=======                                     =======>\n");
    printf("<=======   4: We'll ask how many trials you  =======>\n");
    printf("<=======      want                           =======>\n");
    printf("<=======                                     =======>\n");
    printf("<=======   5: The game will start and ask    =======>\n");
    printf("<=======      you to wish which number did   =======>\n");
    printf("<=======      the computer thought of        =======>\n");
    printf("<=======                                     =======>\n");
    printf("<=======   6: If you find it, then you win   =======>\n");
    printf("<=======      else you'll see                =======>\n");
    printf("<=======                                     =======>\n");
    printf("<=======   May the force be with you         =======>\n");
    printf("<===================================================>\n");
    printf("\n");
    printf("\033[0m"); // reset color to normal

    printf("\033[1;32m"); // green bold color
    printf("So... first question, Do you want to Play a game ? (0=YES / 1=NO): ");
    printf("\033[0m"); // reset color to normal
    scanf("%d", &wantToPlay);

    while (wantToPlay != 0)
    {
        if (wantToPlay == 1)
        {

            printf("\033[1;34m"); // blue bold color
            printf("Well that's really sad, we didn't have the time to know each other, maybe another time :=)\n");
            printf("\033[0m"); // reset color to normal

            break;
        }
        printf("\033[0;31m"); // red color
        printf("Well it looks like you didn't choose a correct option, so please, do you want to Play a game ? (0=YES / 1=NO): ");
        printf("\033[0m"); // reset color to normal
        scanf("%d", &wantToPlay);
    }

    if (wantToPlay == 0)
    {

        printf("\033[1;35m"); // magenta bold color
        printf("Well I'm glad you make it through the first question, let's the game begin\n");
        printf("\033[0m"); // reset color to normal

        //Launch the game setup
        gameSetup();
    }

    return 0;
}

int gameSetup()
{

    // Computer generate a random number between 0 and 1000
    CGuess = rand() % 1000 + 1;

    // Ask player's name
    printf("\033[1;32m"); // green bold color
    printf("Second question, What is your name ? (128 chars. Max): ");
    printf("\033[0m"); // reset color to normal
    scanf("%s", name);

    // Cheer you up
    printf("\033[1;35m"); // magenta bold color
    printf("Welcome to our Game %s\n", name);
    printf("\033[0m"); // reset color to normal

    // Ask player's age
    printf("\033[1;32m"); // green bold color
    printf("Third question, How many trials do you think you need for guessing the computer number ? (Must be a number): ");
    printf("\033[0m"); // reset color to normal
    scanf("%d", &nbOfTrialsAvailable);

    // Tell you how many trials you've got
    printf("\033[1;35m"); // magenta bold color
    printf("You have %d guesses to beat the computer, let's play !!\n", nbOfTrialsAvailable);
    printf("\033[0m"); // reset color to normal

    int nbOfTrialsAvailableAtBeginning = nbOfTrialsAvailable;

    while (gamerGuess != CGuess)
    {

        if (nbOfTrialsAvailable != nbOfTrialsAvailableAtBeginning)
        {
            printf("\033[1;35m"); // magenta bold color
            printf("You have %d guesses left to beat the computer\n", nbOfTrialsAvailable);
            printf("\033[0m"); // reset color to normal
        }
        if (nbOfTrialsAvailable == 0)
        {
            printf("\033[1;31m"); // red bold color
            printf("Sorry you lost because you ran out of available trials, the computer's guessed number was %d, See you next Time :=)\n", CGuess);
            printf("\033[0m"); // reset color to normal

            return 0;
        }
        else
        {
            pRound();
        }
        nbOfTrialsAvailable -= 1;
    }
    return 0;
}

int pRound()
{
    // Ask the player to guess a number
    printf("\033[1;32m"); // green bold color
    printf("Guess the computer number (Between 0 & 1000): ");
    printf("\033[0m"); // reset color to normal
    scanf("%d", &gamerGuess);

    nbOfGuesses += 1;

    if (gamerGuess == CGuess)
    {
        printf("\033[1;35m"); // magenta bold color
        printf("You win against the computer in %d trials, Congrats %s !! \n", nbOfGuesses, name);
        printf("\033[0m"); // reset color to normal

        return 0;
    }
    else if (CGuess - gamerGuess < 0)
    {
        printf("\033[1;34m"); // blue bold color
        printf("It's lower, try again\n");
        printf("\033[0m"); // reset color to normal
    }
    else if (CGuess - gamerGuess > 0)
    {
        printf("\033[1;31m"); // red bold color
        printf("It's bigger, try again\n");
        printf("\033[0m"); // reset color to normal
    }
    else if (CGuess - gamerGuess <= 18)
    {
        printf("\033[1;35m"); // magenta bold color
        printf("You are really close...\n");
        printf("\033[0m"); // reset color to normal
    }
    return 0;
}
