#include "display.hpp"
#include "data.hpp"
#include "kalejdoskopo.h"
#include "term.h"

int	testputc(int c) {
		write(1, &c, 1);
			return 1;
}

void	x::initiate() {
	//windows = new std::vector<Window*>();
	//windows->reserve(WINUMBER);
	d::resource[0] = (void*)malloc(30*120);
	for(int i=0; i<30*120; ++i) {
		((char*)d::resource[0])[i] = '.';
	}
}

int	x::update(unsigned const currFrame) {
	(void)currFrame;
	static char *cl = strdup("cl");
	static char *cm = strdup("cm");
	tputs(tgetstr(cl, NULL), 1, testputc);
	for (const auto depth : d::depth) {
		draw(depth.second);
	}
	tputs(tgoto(tgetstr(cm, NULL), 0, 0), 1, testputc);

		//write(1, (char*)d::resource[0], 120);
	for (int i=0; i<30; ++i) {
		write(1, (char*)d::resource[0]+i*120, 120);
		//write(1, "\n", 1);
		tputs(tgoto(tgetstr(cm, NULL), 1, i+1), 1, testputc);
	}
	return 0;
}

void	x::draw(int const id) {
		((char*)d::resource[0])[d::x[id]+120*d::y[id]] = 'e';
}
