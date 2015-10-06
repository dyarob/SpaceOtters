#include "Game.class.hpp"

int main() {
	std::srand(std::time(NULL));

	//all graphix init
	initscr();
	start_color();
	Game	game;

	game.mainloop(timer);
}
