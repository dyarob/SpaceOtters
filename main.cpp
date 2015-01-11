#include "Timer.class.hpp"
#include "Player.class.hpp"
#include "EnemyBase.class.hpp"
#include "DelayEvent.hpp"
#include "List.struct.hpp"
#include "WinUI_screen.class.hpp"
#include "WinUI_dialogBox.class.hpp"
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



# include   "EnemyBase.class.hpp"

void	updatePositions(List **units, int currentFrame)
{
	List *head = *units;
	for (List *l = *units; l;) {
		l->u->move(l->u->getDeltaV(), currentFrame);
		if (l->u->getCoord().getY() < 0)
			head = List::delete_one(*units, l);
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

	// TEST COLLISIONS
	EnemyBase	*truc = new EnemyBase( *(new Vector2D(3, 25)), *(new Vector2D(0, 0)) );
	units = units->push(truc);

	start_color();
	while (running) {
		if ( !player )
			break;

		if (!player->getHp())
		{
			break;
		}

		if (sigwinchReceived)
		{
			game = new WinUI_screen(120, 30, 1, 0);
			BoxText = new WinUI_dialogBox(120, 3, 31, 0);
			sigwinchReceived = false;
		}

		currentFrame++;
		timer.start();
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
