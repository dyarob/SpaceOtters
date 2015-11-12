#ifndef DATA
#define DATA

#include <boost/unordered_map.hpp>
#include <boost/container/map.hpp>

namespace d {

	typedef boost::unordered_map<unsigned, int>	idhmap_int;
	typedef boost::unordered_map<unsigned, unsigned>	idhmap_uns;
	typedef boost::unordered_map<unsigned, void*>	idhmapvoid;
	typedef boost::container::multimap<unsigned, unsigned>	multimap;

	extern idhmap_int	x;
	extern idhmap_int	y;
	extern idhmap_uns	w;
	extern idhmap_uns	l;
	extern idhmapvoid	resource;
	extern multimap	depth;
	extern unsigned	maxid;

	extern void	initiate();
	extern void	terminate();

}

#endif
