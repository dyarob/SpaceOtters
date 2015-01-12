#ifndef DELAYEVENT_HPP
# define DELAYEVENT_HPP

# include <iostream>
# include "List.struct.hpp"

# define FRAME_MIN_TO_POP_CHAIN 150
# define FRAME_MAX_TO_POP_CHAIN 225
# define CHAIN_MIN_LENGTH 2
# define CHAIN_MAX_LENGTH 5
# define CHAIN_MIN_SPACING 5
# define CHAIN_MAX_SPACING 10
# define TEMP_WIN_X 120
# define TEMP_WIN_Y 30
# define SPAWN_Y_PADDING 2
# define NUMBER_OF_ENEMY_TYPES 1
# define ENEMYBASE 0

class DelayEvent {

public:
	DelayEvent( void );
	~DelayEvent( void );

	// fonction principale qui est appellée à chaque tick 
	void exec( List	**units, int); 

	void	randomChain( List **units, int );

private:
	DelayEvent( DelayEvent const & cp );
	void		createDelayedEnemy( List **, int, int, int, int );
	DelayEvent &	operator=(DelayEvent const &);
	static const int	framesToFillMainShipWeapon = 30;

};

std::ostream & 		operator<<(std::ostream &, DelayEvent const &);

#endif /* DELAYEVENT_HPP */
