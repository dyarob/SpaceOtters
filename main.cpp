#include "Timer.class.hpp"
#include "Player.class.hpp"
#include "DelayEvent.hpp"
#include "List.struct.hpp"
#include "WinUI_screen.class.hpp"
#include "WinUI_dialogBox.class.hpp"
#include <iostream>
#include <thread>
#include <mutex>


# include   "EnemyBase.class.hpp"

void	updatePositions(List *units, int currentFrame)
{

	for (List *l = units; l; l = l->next) {
		/* move element */
		l->u->move(l->u->getDeltaV(), currentFrame);
		if (l->u->getCoord().getY() < 0)
			l = List::delete_one(units, l);
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
	}
}

int main() {

	Timer 			timer(100);
	bool 			running(true);
	unsigned int	currentFrame(0);
	DelayEvent		events;
	Vector2D		playerPos(15, 5);
	Vector2D		playerVel(0, 0);
	Player			*player = new Player(playerPos, playerVel);
	List			*units = new List(player);

	//WinUI_dialogBox *BoxHead = new WinUI_dialogBox(120, 3, 1, 0);
	WinUI_screen *game = new WinUI_screen(120, 30, 1, 0);
	WinUI_dialogBox *BoxText = new WinUI_dialogBox(120, 3, 31, 0);

	// srand
	std::srand(std::time(NULL));

	while (running) {
		currentFrame++;
		timer.start();
		events.exec(&units, currentFrame);
		if (game->keyEvent(player) == std::string("espace"))
			units = units->push(player->shoot());

		updatePositions(units, currentFrame);
		game->update(units);
		BoxText->fixeDialog("GrosBoGoss Francky", currentFrame / 10, 1);
		timer.stop();
		timer.wait();
	}

	delete player;
	delete units;
	delete game;
}
