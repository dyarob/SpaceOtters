#ifndef     _PLAYER_HPP_
# define    _PLAYER_HPP_

# include   <iostream>
# include   "AUnit.class.hpp"
# include   "Vector2D.class.hpp"
# include   "WeaponBase.class.hpp"
# include	"Projectile.class.hpp"

class       Player : public AUnit {

private:
    Player(void);
	static Skin*	skin;

public:
    Player(Vector2D &coord, Vector2D &delta_v);
    Player(Player const & src);

    Player           &operator=(Player const &);

    WeaponBase          &getWeapon(void);

    ~Player();
};

#endif      /* !_PLAYER_HPP_ */

