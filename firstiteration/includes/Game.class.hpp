#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include "CONST.h"
#include "Player.class.hpp"
#include "EnemyBase.class.hpp"
#include "BlockBase.class.hpp"
#include "AsteroidField.class.hpp"
#include "Level.class.hpp"
#include "Spawner.class.hpp"

#include "WinUI_screen.class.hpp"
#include "WinUI_dialogBox.class.hpp"

#include <list>
#include "objlist.class.hpp"
#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
#include <signal.h>
#include <vector>

class	Game {
	private:
		//bool	sigwinchReceived;
		int				lvlId;
		std::vector<Level*>	lvls;
		objlist			objects;
		Player			*player;
		Spawner			spawner;

		WinUI_dialogBox	*topBox;
		WinUI_dialogBox	*bottBox;
		WinUI_screen	*gameScreen;

		void	lvlInit();

		void	keyEvent(Player *player, std::list<AGameObject*> &l);
		void	updatePositions(objlist &units, int const currFrame);
		void	exitGame(void);

	public:
		~Game();
		Game();

		void	update(int const currFrame);
};

#endif //!GAME_CLASS_HPP
