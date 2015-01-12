#include "DelayEvent.hpp"
#include "EnemyBase.class.hpp"

DelayEvent::DelayEvent(void) {
	return;
}

DelayEvent::~DelayEvent(void){
	return;
}

void	DelayEvent::exec(List	**units, int lvl) {
	this->randomChain(units, lvl);
	// recharger la weapon du vaisseau joueur
}

// génère une chaine d'ennemis aleatoire, d'une longueur aleatoire d'ennemis aleatoires.
void	DelayEvent::randomChain( List **units, int lvl ) {
	static int randomWait = 100; // first ennemies pop time
	static int currentCount = 0;

	currentCount++;

	if (randomWait == 0) {
		randomWait = (std::rand() % (FRAME_MAX_TO_POP_CHAIN - FRAME_MIN_TO_POP_CHAIN)) + FRAME_MIN_TO_POP_CHAIN;
	}

	if (currentCount == randomWait) {
		randomWait = 0;
		currentCount = 0;
		int chainLength = (std::rand() % (CHAIN_MAX_LENGTH - CHAIN_MIN_LENGTH)) + CHAIN_MIN_LENGTH + 3 * (lvl);
		int chainSpacing = (std::rand() % (CHAIN_MAX_SPACING - CHAIN_MIN_SPACING)) + CHAIN_MIN_SPACING;
		int chainSpawnY = (std::rand() % (TEMP_WIN_Y - SPAWN_Y_PADDING * 2)) + SPAWN_Y_PADDING;
		int enemyType = std::rand() % NUMBER_OF_ENEMY_TYPES;
		int pattern = std::rand() % 4;

		for (int i = 0; i < chainLength; i++) {
			this->createDelayedEnemy( units, enemyType, (chainSpacing * i), chainSpawnY, pattern);
		}
	}
}

// push un ennemi aléatoire dans la file d'attente
void	DelayEvent::createDelayedEnemy( List **units , int type, int delay, int spawn_y, int pattern ) {
	EnemyBase *newEnnemy = NULL;

	if (type == ENEMYBASE) {
		Vector2D * a = new Vector2D(spawn_y, TEMP_WIN_X + delay);
		Vector2D * b = new Vector2D(0, -5);
		newEnnemy = new EnemyBase(*a, *b, pattern);
	}
	if (newEnnemy != NULL){
		*units = (*units)->push(newEnnemy, 'e');
	}
}
	
std::ostream &		operator<<(std::ostream & o, DelayEvent const & rhs){
	(void)rhs;
	return o;
}
