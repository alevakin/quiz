#include "question.c"

void cls();
void initialize();
void help();
void quiz();

void cls(){

    #ifdef __MINGW32__
        system("cls");
    #endif

    #ifdef __APPLE__
       system("clear");
    #endif

}

void update_view(int mode, int i){

    if(mode == ASK_QUESTION)
    {
        printf("%s\n", questions[i].id);
        printf("A: %s", questions[i].a);
        printf("B: %s", questions[i].b);
        printf("C: %s", questions[i].c);
        printf("D: %s", questions[i].d);

    }else if(mode == ANSWER_QUESTION)
    {
        if(quit == 0)
        {
            cls();
            printf("Richtig! Naechste Frage: \n\n");
        }
        else
        {
            printf("\n\n\nDie richtige Antwort waere %c gewesen!\n\n", rightAnswer_convert(i));
            printf("\nDas Spiel wird beendet, viel Glueck beim naechsten Mal!");
        }

    }else if(mode == GAME_OVER)
    {
        if (quit == 0){
            cls();
            printf("\n\nHerzlichen Glueckwunsch! Du hast alle Fragen richtig beantwortet!\n\n");
        }
        else
            printf("\n\nDu hast immerhin %d Fragen richtig beantwortet.", points);

        printf("\nMoechtest du noch einmal spielen? [y/n]\n");
        play_again();
    }
}

void help(){

    char enter;
    cls();
    printf("Tipp A, B, C oder D bzw. a, b, c oder d.\n\n");
    printf("Gebe S ein, um das Spiel zu starten!\n");
    scanf("%s", &enter);
    if(enter == 'S' || enter == 's'){
        quiz();
    }
}

void initialize(){

    cls();

    char choice,prob;

    printf("\n\n\n\n\n\t\t\t        Q U I Z \n\n\n\n\n\n");
    printf("\n\t\t > Druecke S, um das Spiel zu starten");
    printf("\n\t\t > Druecke H, um das Hilfe-Menue anzuzeigen");
    printf("\n\t\t > Druecke Q, um das Programm zu beenden\n\n\n");

    choice = getchar();
    if(choice == '\n')
        choice = getchar();

    switch(choice){
        case 'S': quiz();
        case 's': quiz();
        case 'H': help();
        case 'h': help();
        case 'Q': exit(0);
        case 'q': exit(0);
    }
} /* menu */

void quiz(){

    cls();
    get_questions();
    cls();

    int i = 0;
 
    while(i < NUMBER_OF_Q){
        if(quit != 1){   //quit is equal 1, when the answer is wrong
            update_view(ASK_QUESTION, i); //questions are displayed

            rightAnswer_convert(i);
            check_answer(i);

            update_view(ANSWER_QUESTION, i);
        }
        i++;
    }

    update_view(GAME_OVER, i);
}

int main(){

    initialize();
    return 0;

}

