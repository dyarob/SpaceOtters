#include "display.hpp"
#include "data.hpp"
#include "libkalejdoskopo.h"
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
	static char *cl = strdup("cl");
	static char *cm = strdup("cm");
	tputs(tgetstr(cl, NULL), 1, testputc);
	write(1, "\033[38;5;161m", 11);
	for (const auto depth : d::depth) {
		draw(depth.second);
	}

	for (int i=0; i<30; ++i) {
		tputs(tgoto(tgetstr(cm, NULL), 0, i), 1, testputc);
		write(1, (char*)d::resource[0]+i*120, 120);
	}
	return currFrame;
}

void	x::draw(int const id) {
		//((char*)d::resource[0])[d::x[id]+120*d::y[id]] = 'e';
		for (unsigned i=0; i<d::l[id]; ++i) {
			memcpy((char*)d::resource[0]+120*(d::y[id]+i)+d::x[id], (char*)d::resource[id]+d::w[id]*i, d::w[id]);
		}
}
