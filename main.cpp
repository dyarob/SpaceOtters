#include <stdlib.h>		//srand
#include <ncurses.h>	//initscr
#include "Timer.class.hpp"
#include "Game.class.hpp"
#include "display.hpp"

void		mainloop(void);
void		freeexit(void);

static Timer 		*t = new Timer(100);
static unsigned	currFrame(0);
static Game			*g = new Game();


int			main(void) {
	srand(time(NULL));
	//ncurses init
	initscr();
	start_color();
	//launch
	mainloop();
	//end
	freeexit();
	return EXIT_SUCCESS;
}

void		mainloop(void) {
	while (currFrame < 100) {
		currFrame++;
		t->start();

		g->update(currFrame);
		x::update(currFrame);

		t->stop();
		t->wait();
	}
}

void		freeexit(void) {
	delete(t);
	delete(g);
}
