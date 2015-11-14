#include <stdlib.h>		//srand
#include <ncurses.h>	//initscr
#include "Timer.class.hpp"
#include "Game.class.hpp"
#include "display.hpp"
#include "data.hpp"
#include "entities.hpp"

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
	x::initiate();
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

		//g->update(currFrame);
		unsigned e = e::create(1,1,1,1,1);
		d::resource[e] = malloc(1);
		*((char*)d::resource[e]) = 'e';
		x::update(currFrame);

		t->stop();
		t->wait();
	}
}

void		freeexit(void) {
	delete(t);
	delete(g);
}
