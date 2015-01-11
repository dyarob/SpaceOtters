#ifndef DELAYEVENT_HPP
# define DELAYEVENT_HPP

# include <iostream>
# include "List.struct.hpp"

# define FRAME_MIN_TO_POP_CHAIN 500
# define FRAME_MAX_TO_POP_CHAIN 1000
# define CHAIN_MIN_LENGTH 3
# define CHAIN_MAX_LENGTH 9
# define CHAIN_MIN_SPACING 100
# define CHAIN_MAX_SPACING 300
# define TEMP_WIN_X 120
# define TEMP_WIN_Y 30
# define SPAWN_Y_PADDING 2
# define NUMBER_OF_ENEMY_TYPES 1
# define ENEMYBASE 0

class DelayEvent {

public:
	DelayEvent( void );
	~DelayEvent( void );
	
	void exec( List	**units, int currentFrame ); // fonction principale qui est appellée à chaque tick 

	void	randomChain( List **units );

private:
	DelayEvent( DelayEvent const & cp );
	void		createDelayedEnemy( List **, int, int, int );
	DelayEvent &	operator=(DelayEvent const &);
	static const int	framesToFillMainShipWeapon = 30;

};

std::ostream & 		operator<<(std::ostream &, DelayEvent const &);

#endif /* DELAYEVENT_HPP */
