#include <iostream>
#include <vector>
#include <unistd.h>
#include <ncurses.h>
#include <menu.h>

class Mainmenu
{
    public:
	    Mainmenu();
	    ~Mainmenu();
	    ITEM** vectorToItemArr(std::vector<ITEM*>& t_vec, ITEM**& item);
    private:
	    void renderMainMenu();
	    WINDOW* m_mainWindow;
	    MENU* m_currentMenu;
	    std::vector<std::string> m_mainMenuItems = {
	        "Gyroscope Output",
                "Accelerometer Output",
	        "Power Management Settings",
	        "Quit" 
	    };
};
