#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

# include "AUnit.class.hpp"
# include "vector2.class.hpp"
# include "WeaponBase.class.hpp"

class       Player : public AUnit {

private:
    Player(void);
    //Player(Player const & src);
    //Player	&operator=(Player const &);

	static Skin*	skin;

public:
    ~Player();
    Player(vector2 coord, vector2 delta_v);

    WeaponBase		&getWeapon(void);
};

#endif      /* !_PLAYER_HPP_ */

