#include "question.h"

struct sQuestion questions[NUMBER_OF_Q]; /* global struct array */
void initialize();
void cls();

char *get_qFileName(){
    char *temp = (char*) malloc(sizeof(char) * FILE_STRING_SIZE);
    printf("Waehle den Fragenbereich: \nMathe\nPolitik\nAllgemeinwissen\nNatur\nEssen\n");
    printf("Deine Wahl: ");
    scanf("%s", temp);

    return temp;
}


void get_questions(){ //read questions from question.txt

    int i = 0;
    int answerBuffer;
    char sBuffer[MAX_STRING_LENGTH];

    FILE *fQuestions = NULL;

    while(fQuestions == NULL){

        char *qFileName = (char*) malloc (sizeof(char) * FILE_STRING_SIZE);
        qFileName = get_qFileName();

        char *folderPath = "questions/";
        char *path = (char*) malloc(sizeof(char) * (strlen(qFileName) + strlen(folderPath) + 4 + 1)); //+4 für ".txt", +1 für terminator

        strcpy(path, folderPath);
        strcat(path, qFileName);
        strcat(path, ".txt");

        fQuestions = fopen(path, "r");
        if (fQuestions == NULL)
            printf("\nDATEI KONNTE NICHT GEOEFFNET WERDEN!\n\n\n");

    }

    for(i = 0; i < NUMBER_OF_Q; i++){

    fgets(sBuffer, MAX_STRING_LENGTH, fQuestions);
        questions[i].id = (char*)malloc(strlen(sBuffer) + 1);
        strcpy(questions[i].id, sBuffer);
    fgets(sBuffer,  MAX_STRING_LENGTH, fQuestions);
        questions[i].a = (char*)malloc(strlen(sBuffer) + 1);
        strcpy(questions[i].a, sBuffer);
    fgets(sBuffer,  MAX_STRING_LENGTH, fQuestions);
        questions[i].b = (char*)malloc(strlen(sBuffer) + 1);
        strcpy(questions[i].b, sBuffer);
    fgets(sBuffer,  MAX_STRING_LENGTH, fQuestions);
        questions[i].c = (char*)malloc(strlen(sBuffer) + 1);
        strcpy(questions[i].c, sBuffer);
    fgets(sBuffer,  MAX_STRING_LENGTH, fQuestions);
        questions[i].d = (char*)malloc(strlen(sBuffer) + 1);
        strcpy(questions[i].d, sBuffer);
    fgets(sBuffer, MAX_STRING_LENGTH, fQuestions);
        switch(sBuffer[0])
        {
        case '1':
        answerBuffer = 1;
        break;
        case '2':
        answerBuffer = 2;
        break;
        case '3':
        answerBuffer = 3;
        break;
        case '4':
        answerBuffer = 4;
        break;
        default:
        printf("\nRichtige Antwort konnte nicht ausgelesen werden!");
        }
    questions[i].rightAnswer = answerBuffer;

    }
}

int get_input_answer() {

	char ans;
	printf("Deine Antwort ist ");
	scanf("%s", &ans);

	if (ans == 97 || ans == 65){
		return 1;
	} else if (ans == 98 || ans == 66){
		return 2;
	} else if (ans == 99 || ans == 67){
		return 3;
	} else if (ans == 100 || ans == 68){
		return 4;
	}
	else {
        printf("Unzulaessige Antwort!\n");
        return get_input_answer();
	}
} /* A, B, C and D are converted to 1, 2, 3 or 4 */

char rightAnswer_convert(int i){

	if (questions[i].rightAnswer == 1){
		return 'A';
	} else if (questions[i].rightAnswer == 2){
		return 'B';
	} else if (questions[i].rightAnswer == 3){
		return 'C';
	} else if (questions[i].rightAnswer == 4){
		return 'D';
	}

} /* the right answer is a char */

int check_answer(int i){ // i is the number of the question

	int answer;
	answer = get_input_answer();

	if(questions[i].rightAnswer == answer){

		points++;
		quit = 0;

	} else if (questions[i].rightAnswer != answer) {

		quit = 1;
	}
} /* check whether the player says the right answer */

void play_again(){
    char y_n;
    scanf("%s", &y_n);
    if(y_n == 'y'|| y_n == 'Y') {
        quit = 0;
        points = 0;
        initialize();
    } else if (y_n == 'n'|| y_n == 'N') {
        cls();
        printf("Bis zum naechsten Mal!\n");
        exit(0);
    }
}