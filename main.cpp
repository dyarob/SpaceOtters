#include <stdlib.h>		//srand
#include <ncurses.h>	//initscr
#include "Timer.class.hpp"
#include "Game.class.hpp"
#include "Display.class.hpp"

void		mainloop(void);
void		freeexit(void);

static Timer 		*t = new Timer(100);
static unsigned	currFrame(0);
static Game			*g = new Game();
static Display	*d = new Display();


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
	delete(t);
	delete(g);
	delete(d);
}
