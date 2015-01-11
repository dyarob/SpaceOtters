#include "Timer.class.hpp"
#include "Player.class.hpp"
#include "DelayEvent.hpp"
#include "List.struct.hpp"
#include "WinUI_screen.class.hpp"
#include "WinUI_dialogBox.class.hpp"
#include <iostream>
#include <thread>
#include <mutex>

void	updatePositions(List *units)
{
	for (List *l = units; l; l = l->next) {
		l->u->move(l->u->getDeltaV());
		if (l->u->getCoord().getX() < 0)
			l->delete_one(units, l);
	}
}

int main() {

	Timer 			timer(100);
	bool 			running(true);
	unsigned int	currentFrame(0);
	DelayEvent		events;
	Vector2D		playerPos(15, 5);
	Vector2D		playerVel(0, 1);
	Player			*player = new Player(playerPos, playerVel);
	List			*units = new List(player);
	//WinUI_dialogBox *BoxHead = new WinUI_dialogBox(120, 3, 1, 0);
	WinUI_screen *game = new WinUI_screen(120, 30, 1, 0);
	WinUI_dialogBox *BoxText = new WinUI_dialogBox(120, 3, 31, 0);

	while (running) {
		BoxText->translateDialog("Bonjour les gens!");
		currentFrame++;
		timer.start();
		events.exec();
		game->keyEvent(player);
		updatePositions(units);
		game->update(units);
		timer.stop();
		timer.wait();
	}

	delete player;
	delete units;
	delete game;
	delete BoxText;
}
