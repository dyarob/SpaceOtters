#include "data.hpp"

boost::unordered_map<unsigned, int>	d::x;
boost::unordered_map<unsigned, int>	d::y;
boost::unordered_map<unsigned, unsigned>	d::w;
boost::unordered_map<unsigned, unsigned>	d::l;
boost::unordered_map<unsigned, void*>	d::resource;
boost::container::multimap<unsigned, unsigned>	d::depth;
unsigned	d::maxid = 1;

void	d::initiate() {
	atexit(d::terminate);
}

void	d::terminate() {
	resource.clear();
}
