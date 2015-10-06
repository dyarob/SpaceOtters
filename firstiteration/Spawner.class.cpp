#include "Spawner.class.hpp"

Spawner::Spawner(void) {
	loadLvl(std::string("test.lvl"));
}

Spawner::~Spawner(void) {
	//need free mem here
}

void	Spawner::spawn(objlist &ol, vector2 const &pos) const {
	ol.push_back(new EnemyBase(pos, vector2(-2, 0), 1));
}

void	Spawner::update(objlist &objects, int currFrame) {
	std::list<objchain*>::iterator	it(chains.begin());
	std::list<objchain*>::iterator	fi(chains.end());
	objects=objects;

	for (; it!=fi && (*it)->sf<currFrame;) {
	// currFrame - it.sf = nb of frames since the chain started.
	// if we % by the period F and it's 0, it's time to spawn an entity!
		if (!((currFrame-(*it)->sf) % (*it)->F)) {
			spawn(objects, (*it)->sp);
			if (!(--(*it)->nu)) {
				delete (*it);
				it = chains.erase(it);
			} else
				++it;
		} else
			++it;
	}
}

void	Spawner::loadLvl(std::string fname) {
	int			sf;
	vector2	sp;
	unsigned short	nu, F, pat;

	std::ifstream	f(fname.c_str(), std::ios::in);
	f.ignore(256, '\n');
	while (f >> sf >> sp.x >> sp.y
			>> nu >> F >> pat) {
		chains.push_back(new objchain(sf, sp, nu, F, pat));
	}
	f.close();
}
