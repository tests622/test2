#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <time.h>
#include "game.h"

char *WordSelect(int difficult)
{
    FILE *wordsDB = NULL;
    char wordPath[260], difficultName[10];

    switch (difficult)
    {
        case 0:
            sprintf(difficultName, "peaceful");
            break;
        case 1:
            sprintf(difficultName, "easy");
            break;
        case 2:
            sprintf(difficultName, "medium");
            break;
        case 3:
            sprintf(difficultName, "hard");
            break;
    }
    sprintf(wordPath, "../res/words/%s.txt", difficultName);
    wordsDB = fopen(wordPath, "r");
    if (wordsDB == NULL)
    {
        printf("Words database \"%s\" not found.\n", wordPath);
        GtkWidget *errWordsMsg = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Error");
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(errWordsMsg), "Words database \"%s\" not found.\n", wordPath);
        gtk_dialog_run(GTK_DIALOG(errWordsMsg));
        gtk_main_quit();
        return NULL;
    }

    int wordsAmount = 0, wordLength = 0;
    char str[10];

    while (!feof(wordsDB))
    {
        fgets(str, 10, wordsDB);
        wordsAmount++;
    }
    
    srand(time(NULL));
    int newWordNum = rand() % wordsAmount;

    fseek(wordsDB, 0, SEEK_SET);

    int i = 0;
    while (i != newWordNum)
    {
        fgets(str, 10, wordsDB);
        i++;
    }
    
    wordLength = strlen(str) - 1;
    char *newWord;
    newWord = (char*)malloc(wordLength*sizeof(char));

    for (i = 0; i < wordLength; i++)
        newWord[i] = str[i];
    newWord[i] = '\0';

    fclose(wordsDB);
    
    return newWord;
}
