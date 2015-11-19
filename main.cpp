#include <stdlib.h>		//srand
#include "libkalejdoskopo.h"
#include "Timer.class.hpp"
#include "display.hpp"
#include "data.hpp"
#include "entities.hpp"

void		mainloop(void);
void		freeexit(void);

static Timer 		*t = new Timer(100);
static unsigned	currFrame(0);


int			main(void) {
	srand(time(NULL));
	terminit();
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

		unsigned e = e::create(1,1,1,1,1);
		unsigned e2 = e::create(2,2,2,2,2);
		d::resource[e] = malloc(1);
		*((char*)d::resource[e]) = 'e';
		d::resource[e2] = strdup("xter");
		x::update(currFrame);

		t->stop();
		t->wait();
	}
}

void		freeexit(void) {
	delete(t);
}
