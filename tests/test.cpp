
#include "WinUI.class.hpp"
#include "WinUI_screen.class.hpp"

int main( void ){	
	WinUI_screen *game = new WinUI_screen();
	WinUI *BoxText = new WinUI(120, 4, 30, 0);

	printw("Press F1 to exit");
	refresh();
	// my_win = create_newwin(height, width, starty, startx);

	mvwprintw(game->win, 1, 1, "x");
	wrefresh(game->win);

	mvwprintw(BoxText->win, 2, 2, "y");
	wrefresh(BoxText->win);
	
	getch();
	game->destroyWin();
	BoxText->destroyWin();

	endwin();			/* End curses mode		  */
	return 0;
}
