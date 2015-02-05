#include <iostream>
#include <ncurses.h>
#include "Skin.class.hpp"

int main (void )
{
	initscr();
	start_color();
	std::cout << "colors : " << (int)COLORS << std::endl;
	std::cout << "color pairs : " << (int)COLOR_PAIRS << std::endl;
	for (int i = 0; i < 1000; ++i) {
		init_pair(i, i%255, i/100);
		attron( COLOR_PAIR(i) );
		//std::cout << "<3";
		printw( "<3" );
	}
	Skin	*sk;
	for (int i = 0; i < 1000; ++i) {
		sk = new Skin('3', i%255, i/100);
		attron( COLOR_PAIR(1000 + i) );
		//std::cout << "<3";
		printw( "<3" );
	}
	(void)sk;
	getch();
	endwin();
	return (0);
}
