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
		if (l->u->getCoord().getY() < 0)
			l->delete_one(units, l);
	}
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
	//WinUI_dialogBox	*BoxHead = new WinUI_dialogBox(120, 3, 1, 0);
	WinUI_screen	*game = new WinUI_screen(120, 30, 1, 0);
	WinUI_dialogBox	*BoxText = new WinUI_dialogBox(120, 3, 31, 0);

	while (running) {
		//signal(SIDWINCH, do_resize);
		currentFrame++;
		timer.start();
		events.exec();
		ch = game->keyEvent(player);
		if ( ch == std::string("espace"))
			units = units->push(player->shoot());
		else if ( ch == std::string("escape"))
			break;
		updatePositions(units);
		game->update(units);
		BoxText->fixeDialog("GrosBoGoss Francky", currentFrame / 10, 1);
		timer.stop();
		timer.wait();
	}

	delete player;
	delete units;
	delete game;
	endwin( );
	return (0);
}
