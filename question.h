#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#define NUMBER_OF_Q 10
#define MAX_STRING_LENGTH 150
#define MAX_POINTS 3

#define FILE_STRING_SIZE 50
#define PATH_SIZE 10

#define ASK_QUESTION 0
#define ANSWER_QUESTION 1
#define GAME_OVER 2

#define ANSWER_DELAY 1500

int points = 0;
int quit = 0;

struct sQuestion //structure of questions
{
    char *id;
    char *a;
    char *b;
    char *c;
    char *d;

    int rightAnswer;
};

