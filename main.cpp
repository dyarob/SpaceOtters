#include "Timer.class.hpp"
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

#define H_MAP 30
#define W_SCREEN 120

static int	sigwinchReceived = true;

static void do_resize(int sig)
{
	(void)sig;
	endwin();
	sigwinchReceived = true;
}

void	generateBlocks(List **units)
{
	int	nb_of_blks = rand() % 2;
	BlockBase	*b;
	int x;

	for (int i = 0; i < nb_of_blks; ++i)
	{
		x = rand() % H_MAP;
		b = new BlockBase( *(new Vector2D(x, W_SCREEN) ) );
		*units = (*units)->push( b );
	}
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

	signal(SIGWINCH, do_resize);

	//WinUI_dialogBox	*BoxHead = new WinUI_dialogBox(120, 3, 1, 0);
	WinUI_screen	*game = new WinUI_screen(120, 30, 1, 0);
	WinUI_dialogBox	*BoxText = new WinUI_dialogBox(120, 3, 31, 0);

	// srand
	std::srand(std::time(NULL));

	// TEST COLLISIONS
	EnemyBase	*truc = new EnemyBase( *(new Vector2D(3, 25)), *(new Vector2D(0, 0)), -1 );
	units = units->push(truc);

	// TEST BLOCKS
	BlockBase	*b1 = new BlockBase( *(new Vector2D(23, 15) ) );
	units = units->push( b1 );
	BlockBase	*b2 = new BlockBase( *(new Vector2D(24, 15) ) );
	units = units->push( b2 );
	BlockBase	*b3 = new BlockBase( *(new Vector2D(23, 16) ) );
	units = units->push( b3 );
	BlockBase	*b4 = new BlockBase( *(new Vector2D(4, 15) ) );
	units = units->push( b4 );
	BlockBase	*b5 = new BlockBase( *(new Vector2D(3, 15) ) );
	units = units->push( b5 );

	start_color();
	while (running)
	{
		if (!player->getHp())
			break;

		if (sigwinchReceived)
		{
			game = new WinUI_screen(120, 30, 1, 0);
			BoxText = new WinUI_dialogBox(120, 3, 31, 0);
			sigwinchReceived = false;
		}

		currentFrame++;
		timer.start();
		generateBlocks(&units);
		events.exec(&units, currentFrame);
		ch = game->keyEvent(player);
		if ( ch == std::string("espace"))
			units = units->push(player->shoot());
		else if ( ch == std::string("escape"))
			break;

		updatePositions(&units, currentFrame);
		game->update(units);
		BoxText->fixeDialog("GrosBoGoss Francky, BoGoss James", currentFrame / 10, 1);
		timer.stop();
		timer.wait();
	}

	delete player;
	delete units;
	delete BoxText;
	delete game;
	return (0);
}
