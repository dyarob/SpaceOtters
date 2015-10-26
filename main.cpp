#include <stdlib.h>		//srand
#include <ncurses.h>	//initscr
#include "Game.class.hpp"
#include "Timer.class.hpp"

void		mainloop(void);
void		freeexit(void);

static	Timer 		*t = new Timer(100);
static	unsigned	currFrame(0);
static	Game			*g = new Game();


int			main(void) {
	srand(time(NULL));

	initscr();
	start_color();

	mainloop();

	freeexit();
	return EXIT_SUCCESS;
}

void		mainloop(void) {
	while (currFrame < 100) {
		currFrame++;
		t->start();

		g->update(currFrame);
		//display.update();

		t->stop();
		t->wait();
	}
}

void		freeexit(void) {
	free(t);
	free(g);
}
