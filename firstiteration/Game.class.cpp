#include "Game.class.hpp"

//*structors
Game::~Game(void){}

Game::Game(void)// :
//	sigwinchReceived(true)
{
	topBox = new WinUI_dialogBox(W_SCREEN, 3, 0, 0);
	bottBox = new WinUI_dialogBox(W_SCREEN, 3, H_MAP+3, 0);
	gameScreen = new WinUI_screen(W_SCREEN, H_MAP, 3, 0);
	player = new Player(vector2(5, 15), vector2(0,0));
	objects.push_back(player);
	Level::lvlsInit();
}

//!*structors

/*
void do_resize(int sig)
{
	(void)sig;
	endwin();
	sigwinchReceived = true;
}
*/
/*
void	segfault(List *l) {
	std::cout << l->type;
}
*/

void	Game::keyEvent(Player *player, std::list<AGameObject*> &l){
	timeout(0);
	int  ch  = getch();
	switch (ch){
		case 'w':
			if (player->pos.y > 1)
				--player->pos.y;
			return ;
		case 'a':
			if (player->pos.x > 1)
				--player->pos.x;
			return ;
		case ' ':
			l.push_back(player->shoot());
			return ;
		case 'd':
			if (player->pos.x < W_SCREEN - 2)
				++player->pos.x;
			return ;
		case 's':
			if (player->pos.y < H_MAP - 2)
				++player->pos.y;
			return ;
		case 27:	// escape
			if (getch() == -1)
				exitGame();
			return ;
		default:
			return ;
	}
}

		/* enemies' pattern...
		if ((*it)->getId() != 0) { // change pattern for everyone but Player's shippu
			if ((*it)->getPattern() == 1) {// pattern un coup en bas un coup en haut
				if (curr_frame % 100 == 1) {
					if ((*it)->getDeltaV().getX() == 0 || (*it)->getDeltaV().getX() == -100) {
						if ((*it)->getCoord().getX() > 2)// on ne sort pas de la map
							(*it)->getDeltaV().setX(100);
					} else {
						if ((*it)->getCoord().getX() < 28)// on ne sort pas de la map
							(*it)->getDeltaV().setX(-100);
					}
				}
			}
			if ((*it)->getPattern() == 2) {
				if ((*it)->getCoord().getY() <= 100) {
					if ((*it)->getDeltaV().getX() == 0 && (*it)->getCoord().getX() != 20) {
						(*it)->getDeltaV().setX(10);
					}
					if ((*it)->getCoord().getX() > 20) {
						(*it)->getDeltaV().setX(-5);
					} else if ((*it)->getCoord().getX() == 20) {
						(*it)->getDeltaV().setX(0);
						if ((*it)->getCoord().getY() <= 50) {
							(*it)->getDeltaV().setY(std::rand() % 10 + 5);
						}
					}
				}
			}
			if ((*it)->getPattern() == 3) {
				if ((*it)->getCoord().getY() <= 100) {
					if ((*it)->getDeltaV().getX() == 0 && (*it)->getCoord().getX() != 10) {
						(*it)->getDeltaV().setX(10);
					}
					if ((*it)->getCoord().getX() > 10) {
						(*it)->getDeltaV().setX(-5);
					} else if ((*it)->getCoord().getX() == 10) {
						(*it)->getDeltaV().setX(0);
						if ((*it)->getCoord().getY() <= 50) {
							(*it)->getDeltaV().setY(- 1 * (std::rand() % 10) - 5);
						}
					}
				}
			}
		}
		*/

void	Game::update(int const currFrame) {
	//signal(SIGWINCH, do_resize);
	if (player->pos.x >= W_SCREEN - (W_SCREEN >> 2)) { // player->won the level
		if ( ++Level::id >= NB_LVL )
			exitGame();
		endwin();
		//sigwinchReceived = 1;
		objects.clear();
		player = new Player(vector2(5, 15), vector2(0,0));
		objects.push_back(player);
	}
	/*
	if (sigwinchReceived) {
		topBox = new WinUI_dialogBox(120, 3, 0, 0);
		gameScreen = new WinUI_screen(120, 30, 3, 0);
		bottBox = new WinUI_dialogBox(120, 3, 33, 0);
		sigwinchReceived = false;
	}
	*/

	keyEvent(player, objects);

	//logical update
	objects.moveAll(currFrame);
	objects.collisions();
	if (player->hp <= 0)
		exitGame();
	objects.clean();

	//new blocs and ennemies generation
	Level::update(objects);
	spawner.update(objects, currFrame);
	//events.exec(&objects, currFrame);
	/* enemies shoot
	for (List *l = objects; l; l = l->next) {
		if (!(rand() % 500 / (Level::id * 2 + 1)) && l->type == 'e')
			objects = objects->push(((EnemyBase*)l->u)->shoot(), 'm');
	}
	*/

	//graphical update
	gameScreen->update(objects);
	bottBox->fixeDialog(Level::lvls[Level::id]->name, currFrame / 10, 1);
}

void	Game::exitGame(void) {
	delete topBox;
	delete bottBox;
	delete gameScreen;
	objects.clear();
	exit(0);
}
