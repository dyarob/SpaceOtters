#include "Game.class.hpp"

//*structors
Game::~Game(void){}

Game::Game(void)// :
//	sigwinchReceived(true)
{
	topBox = new WinUI_dialogBox(W_SCREEN, 3, 0, 0);
	bottBox = new WinUI_dialogBox(W_SCREEN, 3, H_MAP+3, 0);
	gameScreen = new WinUI_screen(W_SCREEN, H_MAP, 3, 0);
	vector2	playerPos(15, 5);
	vector2	playerVel(0, 0);
	player = new Player(playerPos, playerVel);
	objects.push_back(player);
	lvlInit();
	//DelayEvent		events;
}

void	Game::lvlInit(void) {
	lvlId = 0;
	lvls = std::vector<Level*>(NB_LVL);
	lvls[1] = new Level ("Face Zaz, the final boss!", -1 );
	lvls[3] = new Level ("Level 1 - Asteroid field", -2 );
	lvls[0] = new Level ("Level 2 - Asteroid field", -3 );
	lvls[2] = new Level ("Level 3 - Asteroid field", -1 );
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
	std::cerr << "jusque la tout va bien";
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
				return ;
			return ;
		default:
			return ;
	}
}

void	Game::updatePositions(std::list<AGameObject*> &objects, int const curr_frame) {
	std::list<AGameObject*>::iterator	it(objects.begin());
	std::list<AGameObject*>::iterator	end(objects.end());

	for (; it!=end; ++it) {
		std::cerr<<**it; //!
		std::cerr<<"premove";
		(*it)->move(curr_frame);
		std::cerr<<"postmove\npreerase";
		if ((*it)->pos.y <= 0) {
			objects.erase(it);
		}
		std::cerr<<"posterase";
		/*
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

		std::cerr<<"\npre detect_collision";
		(*it)->detect_collision(objects);
		std::cerr<<"post detect_collision\n";
	}
	for (it=objects.begin(); it!=end;) {
		std::cerr<<"on examine:"<<**it;
		if ((*it)->hp <= 0) {
			std::cerr<<"\non le delete!\n";
			delete (*it);
			std::cerr<<"\non l'erase!\n";
			it = objects.erase(it);
			std::cerr<<"et voila!";
		} else
			++it;
	}
	std::cerr<< "\nen fait tout s'est bien passe.";
}

void	Game::update(int const currFrame) {
	//signal(SIGWINCH, do_resize);
	if (player->hp <= 0)
		exitGame();

	if (player->pos.x >= W_SCREEN - (W_SCREEN >> 2)) { // player->won the level
		lvlId++;
		if ( lvlId >= NB_LVL )
			exitGame();
		endwin();
		//sigwinchReceived = 1;
		objects.clear();//on supprimme rien la?!
		delete player;
		player = new Player( *(new vector2(15, 5)), *(new vector2(0,0)));//player->os, player->el );
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

	//lvls[lvlId]->af->generateBlocks(&objects);
	//events.exec(&objects, currFrame);

	keyEvent(player, objects);

	/*
	for (List *l = objects; l; l = l->next) {
		if (!(rand() % 500 / (lvlId * 2 + 1)) && l->type == 'e')
			objects = objects->push(((EnemyBase*)l->u)->shoot(), 'm');
	}
	*/

	std::cerr << "avant";
	updatePositions(objects, currFrame);
	std::cerr << "apres";
	gameScreen->update(objects);

	//bottBox->fixeDialog("GrosBoGoss Francky, BoGoss James", currFrame / 10, 1);
	bottBox->fixeDialog(lvls[lvlId]->name, currFrame / 10, 1);
}

void	Game::exitGame(void) {
	delete topBox;
	delete bottBox;
	delete gameScreen;
	delete player;
	objects.clear();//on supprime rien la?!
	exit(0);
}
