# include				"CONST.h"
#include "Timer.class.hpp"
#include "Level.class.hpp"
#include "AsteroidField.class.hpp"
#include "Player.class.hpp"
#include "EnemyBase.class.hpp"
#include "BlockBase.class.hpp"
#include "DelayEvent.hpp"
#include "List.struct.hpp"
#include "WinUI_screen.class.hpp"
#include "WinUI_dialogBox.class.hpp"
#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
#include <signal.h>
#include "EnemyBase.class.hpp"

static int	sigwinchReceived = true;

static void do_resize(int sig)
{
	(void)sig;
	endwin();
	sigwinchReceived = true;
}

void	segfault(List *l) {
	std::cout << l->type;
}

void	updatePositions(List **units, int currentFrame)
{
	List	*head = *units;
	for (List *l = *units; l;) {
		/* move element */
		l->u->move(l->u->getDeltaV(), currentFrame);
		if (l->u->getCoord().getY() <= 0)
			head = List::delete_one(head, l);
		/* change pattern for everyone but Player's shippu */
		if (l->u->getId() != 0) {
			// pattern un coup en bas un coup en haut
			if (l->u->getPattern() == 1) {
				if (currentFrame % 100 == 1) {
					if (l->u->getDeltaV().getX() == 0 || l->u->getDeltaV().getX() == -100) {
						// on ne sort pas de la map
						if (l->u->getCoord().getX() > 2)
							l->u->getDeltaV().setX(100);
					} else {
						// on ne sort pas de la map
						if (l->u->getCoord().getX() < 28)
							l->u->getDeltaV().setX(-100);
					}
				}
			}
			if (l->u->getPattern() == 2) {
				if (l->u->getCoord().getY() <= 100) {
					if (l->u->getDeltaV().getX() == 0 && l->u->getCoord().getX() != 20) {
						l->u->getDeltaV().setX(10);
					}
					if (l->u->getCoord().getX() > 20) {
						l->u->getDeltaV().setX(-5);
					} else if (l->u->getCoord().getX() == 20) {
						l->u->getDeltaV().setX(0);
						if (l->u->getCoord().getY() <= 50) {
							l->u->getDeltaV().setY(std::rand() % 10 + 5);
						}
					}
				}
			}
			if (l->u->getPattern() == 3) {
				if (l->u->getCoord().getY() <= 100) {
					if (l->u->getDeltaV().getX() == 0 && l->u->getCoord().getX() != 10) {
						l->u->getDeltaV().setX(10);
					}
					if (l->u->getCoord().getX() > 10) {
						l->u->getDeltaV().setX(-5);
					} else if (l->u->getCoord().getX() == 10) {
						l->u->getDeltaV().setX(0);
						if (l->u->getCoord().getY() <= 50) {
							l->u->getDeltaV().setY(- 1 * (std::rand() % 10) - 5);
						}
					}
				}
			}
		}
		l = l->u->detect_collision( &head, l );
	}
	*units = head;
}

int main() {

	Timer 			timer(100);
	bool 			running(true);
	std::string		ch = "";
	unsigned int	currentFrame(0);
	DelayEvent		events;
	Vector2D		playerPos(15, 5);
	Vector2D		playerVel(0, 0);
	Player			*player = new Player(playerPos, playerVel);
	List			*units = new List(player);

	units->setType('p');
	//Level			*lvl = new Level( "Level 1 - Asteroid field", -2 );

	signal(SIGWINCH, do_resize);

	WinUI_dialogBox	*BoxHead = new WinUI_dialogBox(120, 3, 0, 0);
	WinUI_screen	*game = new WinUI_screen(120, 30, 3, 0);
	WinUI_dialogBox	*BoxText = new WinUI_dialogBox(120, 3, 33, 0);

	// level initialization and message
	//lvl->init(BoxText);
	int				lvlId = 0;
	Level			*lvls[NB_LVL];
	lvls[0] = new Level ("Level 1 - Asteroid field", -2 );
	lvls[1] = new Level ("Level 2 - Asteroid field", -3 );
	lvls[2] = new Level ("Level 3 - Asteroid field", -1 );

	// srand
	std::srand(std::time(NULL));

	start_color();
	while (running)
	{
		if (player->getHp() <= 0)
			break;

		if (player->getCoord().getY() >= W_SCREEN - (W_SCREEN >> 2)) // player won the level
		{
			lvlId++;
			if ( lvlId >= NB_LVL )
				break;
			endwin();
			sigwinchReceived = 1;
			List::delete_all(units);
			player = new Player( *(new Vector2D(15, 5)), *(new Vector2D(0,0)));//playerPos, playerVel );
			units = new List( player );
		}

		if (sigwinchReceived)
		{
			BoxHead = new WinUI_dialogBox(120, 3, 0, 0);
			game = new WinUI_screen(120, 30, 3, 0);
			BoxText = new WinUI_dialogBox(120, 3, 33, 0);
			sigwinchReceived = false;
		}

		currentFrame++;
		timer.start();
		lvls[lvlId]->af->generateBlocks(&units);
		events.exec(&units, lvlId);
		ch = game->keyEvent(player);
		if ( ch == std::string("espace"))
			units = units->push(player->shoot(), 'p');
		else if ( ch == std::string("escape"))
			break;

		for (List *l = units; l; l = l->next) {
			if (!(rand() % 500 / (lvlId * 2 + 1)) && l->type == 'e')
				units = units->push(((EnemyBase*)l->u)->shoot(), 'm');
		}

		updatePositions(&units, currentFrame);
		game->update(units);
		//BoxText->fixeDialog("GrosBoGoss Francky, BoGoss James", currentFrame / 10, 1);
		BoxText->fixeDialog(lvls[lvlId]->name, currentFrame / 10, 1);
		timer.stop();
		timer.wait();
	}
	delete BoxHead;
	delete player;
	delete units;
	delete BoxText;
	delete game;
	return (0);
}
