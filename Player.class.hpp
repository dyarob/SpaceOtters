#ifndef     _PLAYER_HPP_
# define    _PLAYER_HPP_

# include   <iostream>
# include   "AUnit.class.hpp"
# include   "Vector2D.class.hpp"
# include   "WeaponBase.class.hpp"

class       Player : public AUnit {

private:
    Player(void);

public:
    Player(Vector2D &coord, Vector2D &delta_v);
    Player(Player const & src);

    Player           &operator=(Player const &);

    WeaponBase          &getWeapon(void);

    void    shoot(Weapon const &)   const;
    ~Player();
};

#endif      /* !_PLAYER_HPP_ */

