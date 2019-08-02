#include <menu.h>
#include "menu.h"

Mainmenu::Mainmenu()
{
    initscr();
    noecho();
    start_color();
    init_pair(1,COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw("Test\n");
    refresh();
    sleep(5);
}

Mainmenu::~Mainmenu()
{
    endwin();
}
