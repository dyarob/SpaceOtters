#include "data.hpp"

boost::unordered_map<unsigned, int>	d::x;
boost::unordered_map<unsigned, int>	d::y;
boost::unordered_map<unsigned, int>	d::w;
boost::unordered_map<unsigned, int>	d::l;
boost::unordered_map<unsigned, void*>	d::resource;
boost::container::multimap<unsigned, unsigned>	d::depth;

void	d::initiate() {
	atexit(d::terminate);
}

void	d::foreach(idhmap_int	*map) {
}

void	d::terminate() {
	resource.clear();
}