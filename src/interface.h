#ifndef INTERFACE_H
#define INTERFACE_H

#include <gtk/gtk.h>

#define UI_FILE "../res/interface.glade"

GtkBuilder *builder;
GtkWidget *difficultWindow, *gameWindow, *msgWindow;
GtkRadioButton *difficult0, *difficult1, *difficult2, *difficult3;
GtkButton *startButton, *exitButton;
GtkLabel *hiddenWordLabel, *gameMsg, *winAmount, *loseAmount;
GtkGrid *alphabetGrid;
GtkImage *hangmanImage;

#endif
