

#include "WinUI.class.hpp"

int main( void ){	
	// WINDOW *my_win;
	// int startx, starty, width, height;

	// initscr();			/* Start curses mode 		*/
	// cbreak();			/* Line buffering disabled, Pass on
	// 					 * everty thing to me 		*/
	// keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

	// height =10; 
	// width = 15;
	// starty = (LINES - height) / 2;	/* Calculating for a center placement */
	// startx = (COLS - width) / 2;	/* of the window		*/
	WinUI *game = new WinUI();
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