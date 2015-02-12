#include "CONST.h"
#include "Game.class.hpp"
#include "Timer.class.hpp"

int main() {
	Timer 			timer(100);
	unsigned int	currentFrame(0);

	std::srand(std::time(NULL));

	//all graphix init
	initscr();
	start_color();
	Game	game;

	while (1) {
		currentFrame++;
		timer.start();

		game.update(currentFrame);

		timer.stop();
		timer.wait();
	}
}
