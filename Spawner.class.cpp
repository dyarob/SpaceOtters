#include "Spawner.class.hpp"

Spawner::Spawner(void) {
}

Spawner::~Spawner(void) {
}

void	Spawner::spawn(objlist &ol, vector2 const &pos) {
	ol.push_back(new EnemyBase(pos, vector2(-2, 0), 1));
}
