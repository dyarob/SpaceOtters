#ifndef DATA
#define DATA

#include <boost/unordered_map.hpp>
#include <boost/container/map.hpp>

namespace d {

	typedef boost::unordered_map<unsigned, int>	idhmap_int;
	typedef boost::unordered_map<unsigned, void*>	idhmap_void;
	typedef boost::container::multimap<unsigned, unsigned>	multimap;

	extern idhmap_int	x;
	extern idhmap_int	y;
	extern idhmap_int	w;
	extern idhmap_int	l;
	extern idhmap_void	resource;
	extern multimap	depth;

	extern void	initiate();
	extern void	terminate();

}

#endif
