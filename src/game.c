#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "word_select.h"
#include "hangman.h"
#include "interface.h"
#include "game.h"

int difficult = 0;

void difficultSet(GtkToggleButton *button)
{
    if (gtk_toggle_button_get_active(button))
    {
        const char *diffname = gtk_button_get_label(GTK_BUTTON(button));
        if (!strcmp(diffname, "Peaceful"))
            difficult = 0;
        else if (!strcmp(diffname, "Easy"))
            difficult = 1;
        else if (!strcmp(diffname, "Medium"))
            difficult = 2;
        else if (!strcmp(diffname, "Hard"))
            difficult = 3;
    }
}

void startGame()
{
    int i;
    errAmount = 0;
    gtk_image_set_from_file(hangmanImage, "../res/pics/0.png");
    gtk_widget_hide(difficultWindow);
    gtk_widget_hide(msgWindow);
    gtk_widget_show_all(GTK_WIDGET(alphabetGrid));

    if (!(wordOfTheGame = WordSelect(difficult)))
        return;
    printf("Word: %s\n", wordOfTheGame);

    for (wordSize = 0; wordOfTheGame[wordSize] != '\0'; wordSize++);

    hiddenWord = (char*)malloc(wordSize*sizeof(char));
    for (i = 0; i < wordSize; i++)
        hiddenWord[i] = '-';
    hiddenWord[i] = '\0';

    gtk_label_set_text(hiddenWordLabel, hiddenWord);
    gtk_widget_show(gameWindow);
}

void replayGame()
{
    gtk_widget_hide(gameWindow);
    gtk_widget_hide(msgWindow);
    gtk_widget_show(difficultWindow);
}
