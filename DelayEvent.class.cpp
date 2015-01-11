#include "DelayEvent.hpp"
#include "EnemyBase.class.hpp"

DelayEvent::DelayEvent(void) {
	return;
}

DelayEvent::~DelayEvent(void){
	return;
}

void DelayEvent::exec() {
	// créer aléatoirement des chaines d'units

	// recharger la weapon du vaisseau joueur


}

// génère une chaine d'ennemis aleatoire, d'une longueur aleatoire d'ennemis aleatoires.
void	DelayEvent::randomChain() {
	static int randomWait = (std::rand() % (FRAME_MAX_TO_POP_CHAIN - FRAME_MIN_TO_POP_CHAIN)) + FRAME_MIN_TO_POP_CHAIN;
	static int currentCount = 0;
	currentCount++;
	if (currentCount == randomWait) {
		randomWait = (std::rand() % (FRAME_MAX_TO_POP_CHAIN - FRAME_MIN_TO_POP_CHAIN)) + FRAME_MIN_TO_POP_CHAIN;
		currentCount = 0;
		int chainLength = (std::rand() % (CHAIN_MAX_LENGTH - CHAIN_MIN_LENGTH)) + CHAIN_MIN_LENGTH;
		int chainSpacing = (std::rand() % (CHAIN_MAX_SPACING - CHAIN_MIN_SPACING)) + CHAIN_MIN_SPACING;
		int chainSpawnY = (std::rand() % (TEMP_WIN_Y - SPAWN_Y_PADDING * 2)) + SPAWN_Y_PADDING;
		int enemyType = std::rand() % NUMBER_OF_ENEMY_TYPES;

		for (int i = 0; i < chainLength; i++) {
			lastEvent.pushBack(enemyType, (chainSpacing * (i + 1)), chainSpawnY);
		}
		return this->lastEvent;
	}
	return this->firstEvent;
}

// push un ennemi aléatoire dans la file d'attente
void DelayEvent::createDelayedEnemy(int type, int delay, int spawn_y) {
	lastEvent.pushBack(type, delay, spawn_y);
}
	
std::ostream &		operator<<(std::ostream & o, DelayEvent const & rhs){
	(void)rhs;
	return o;
}
