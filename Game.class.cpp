#include "Game.class.hpp"

int mainloop() {
	Timer 			timer(100);
	unsigned int	currentFrame(0);

	while (1) {
		currentFrame++;
		timer.start();

		update(currentFrame);

		timer.stop();
		timer.wait();
	}
}

int update(int currentFrame) {
	exitGame(0);
}

void	Game::exitGame(int ret) {
	//delete topBox;
	//delete bottBox;
	//delete gameScreen;
	//objects.clear();
	exit(ret);
}
