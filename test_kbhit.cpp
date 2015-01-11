
#include <iostream>
#include <ncurses.h>

int main( void ){

	initscr();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	std::cout << "Main_Test" << std::endl;

	while (1){
		erase();
		if (getch() == 'q')
			break;
		printw("coucou");
		refresh();
	}


	endwin();
	return 0;
}
