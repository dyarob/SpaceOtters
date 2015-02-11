#include "CONST.h"
#include "Player.class.hpp"
#include "EnemyBase.class.hpp"
#include "E_Zaz.class.hpp"
#include "DelayEvent.hpp"
#include "BlockBase.class.hpp"
#include "AsteroidField.class.hpp"
#include "Level.class.hpp"

#include "Timer.class.hpp"
#include "WinUI_screen.class.hpp"
#include "WinUI_dialogBox.class.hpp"

#include <list>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
#include <signal.h>

static int	sigwinchReceived = true;

static void do_resize(int sig)
{
	(void)sig;
	endwin();
	sigwinchReceived = true;
}

/*
void	segfault(List *l) {
	std::cout << l->type;
}
*/

void	keyEvent(Player *player, std::list<AGameObject*> &l){
	timeout(0);
	int  ch  = getch();
	switch (ch){
		case 'w':
			if (player.pos.y > 1)
				--player.pos.y;
			return ;
		case 'a':
			if (player.pos.x > 1)
				--player.pos.x;
			return ;
		case ' ':
			l.push_back(player->shoot());
			return ;
		case 'd':
			if (player.pos.x < W_SCREEN - 2)
				++player.pos.x;
			return ;
		case 's':
			if (player.pos.y < H_MAP - 2)
				++player.pos.y;
			return ;
		case 27:	// escape
			if (getch() == -1)
				return ;
			return ;
		default:
			return ;
	}
}

void	updatePositions(std::list<AGameObject*> &units, int const curr_frame)
{
	std::list<AGameObject*>::iterator	it(units.begin());
	std::list<AGameObject*>::iterator	end(units.end());

	for (; it!=end; ++it) {
		(*it)->move(curr_frame);
		if ((*it)->getCoord().getY() <= 0) {
			units.erase(it);
		}
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

		detect_collision(units);
	}
	for (it=it.begin(); it!=end; ++it) {
		if ((*it)->hp <= 0) {
			delete (*it);
			l.erase(it);
			--it;
			--end;
		}
	}
}

int main() {
	Timer 			timer(100);
	bool 			running(true);
	std::string		ch = "";
	unsigned int	currentFrame(0);
	DelayEvent		events;

	std::srand(std::time(NULL));

	//all graphix init
	initscr();
	start_color();
	WinUI_dialogBox	*BoxHead = new WinUI_dialogBox(W_SCREEN, 3, 0, 0);
	WinUI_screen	*game = new WinUI_screen(W_SCREEN, H_MAP, 3, 0);
	WinUI_dialogBox	*BoxText = new WinUI_dialogBox(W_SCREEN, 3, H_MAP+3, 0);

	vector2	playerPos(15, 5);
	vector2	playerVel(0, 0);
	Player		*player = new Player(playerPos, playerVel);
	std::list<AGameObject*>	units;
	units.push_back(player);
	//units->setType('p');
	//E_Zaz		*zaz = new E_Zaz( *(new vector2(1, 67)), *(new vector2(0, 0)), 0);

	signal(SIGWINCH, do_resize);

	// level initialization
	int				lvlId = 0;
	Level			*lvls[NB_LVL];
	lvls[1] = new Level ("Face Zaz, the final boss!", -1 );
	lvls[3] = new Level ("Level 1 - Asteroid field", -2 );
	lvls[0] = new Level ("Level 2 - Asteroid field", -3 );
	lvls[2] = new Level ("Level 3 - Asteroid field", -1 );

	while (running) {
		if (player->getHp() <= 0)
			break;

		if (player->getCoord().getY() >= W_SCREEN - (W_SCREEN >> 2)) { // player won the level
			lvlId++;
			if ( lvlId >= NB_LVL )
				break;
			endwin();
			sigwinchReceived = 1;
			units.clear();
			player = new Player( *(new vector2(15, 5)), *(new vector2(0,0)));//playerPos, playerVel );
			units.push_back(player);
			/*
			if (lvlId == ZAZ_LVL) {
				units = units->push(zaz, 'e');
			}
			*/
		}

		if (sigwinchReceived) {
			BoxHead = new WinUI_dialogBox(120, 3, 0, 0);
			game = new WinUI_screen(120, 30, 3, 0);
			BoxText = new WinUI_dialogBox(120, 3, 33, 0);
			sigwinchReceived = false;
		}

		currentFrame++;
		timer.start();
		//lvls[lvlId]->af->generateBlocks(&units);

		/*
		if (lvlId != ZAZ_LVL)	// except for boss level
			events.exec(&units, currentFrame);
		else
			units = units->push(zaz, 'e');
		*/

		keyEvent(player, units);

		/*
		for (List *l = units; l; l = l->next) {
			if (!(rand() % 500 / (lvlId * 2 + 1)) && l->type == 'e')
				units = units->push(((EnemyBase*)l->u)->shoot(), 'm');
		}
		*/
			//PRIORITAIRE
		updatePositions(units, currentFrame);
		game->update(units);

		//BoxText->fixeDialog("GrosBoGoss Francky, BoGoss James", currentFrame / 10, 1);
		BoxText->fixeDialog(lvls[lvlId]->name, currentFrame / 10, 1);
		timer.stop();
		timer.wait();
	}

	delete BoxHead;
	delete player;
	units.clear();
	delete BoxText;
	delete game;
	return (0);
}
