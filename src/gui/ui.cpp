#include <memory>
#include <menu.h>
#include "ui.h"

Mainmenu::Mainmenu()
{
    initscr();
    noecho();
    start_color();
    init_pair(1,COLOR_RED, COLOR_BLACK);
    init_pair(2,COLOR_CYAN, COLOR_BLACK);

    attroff(COLOR_PAIR(1));
    //printw("Test\n");

    renderMainMenu();

    refresh();
    sleep(5);
}

Mainmenu::~Mainmenu()
{
    unpost_menu(m_currentMenu);
    free_menu(m_currentMenu);
    endwin();
}

void Mainmenu::renderMainMenu()
{
    std::vector<ITEM*> my_items;
    for (auto& choice : m_mainMenuItems)
    {
	const char* c_str = choice.data();
        my_items.push_back(new_item(c_str,c_str));
    }

    ITEM** items = (ITEM **)calloc(my_items.size(), sizeof(ITEM*));
    //std::unique_ptr<ITEM**> items = std::make_unique<ITEM**>(my_items.size());
    items = vectorToItemArr(my_items, items);

    m_currentMenu = new_menu(items);
    m_mainWindow = newwin(10, 40, 4, 4);
}

ITEM** Mainmenu::vectorToItemArr(std::vector<ITEM*>& t_vec, ITEM**& items)
{
    for (unsigned int i = 0; i < t_vec.size(); i++ )
    {
        items[i] = t_vec.at(i);
    }
    return items;
}

