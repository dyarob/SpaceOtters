#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include "Timer.class.hpp"

class	Game {
	int	mainloop();
	int	update(int const currFrame);
	void	exitGame(void);
};

#endif
