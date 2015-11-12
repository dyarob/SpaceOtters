#include "entities.hpp"
#include "data.hpp"

unsigned	e::create(int x, int y, unsigned w, unsigned l, unsigned d) {
	d::x[d::maxid] = x;
	d::y[d::maxid] = y;
	d::w[d::maxid] = w;
	d::l[d::maxid] = l;
	d::depth.emplace(d::maxid, d);
	return (d::maxid)++;
}
