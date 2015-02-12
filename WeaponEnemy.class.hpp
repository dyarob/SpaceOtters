#ifndef     _WEAPON_ENEMY_HPP_
# define    _WEAPON_ENEMY_HPP_

# include   <iostream>
# include	"Weapon.class.hpp"
# include   "ProjectileEnemy.class.hpp"

class       WeaponEnemy : public Weapon {

protected:
    unsigned int    _fire_rate;

public:
    WeaponEnemy(void);
    //WeaponEnemy(WeaponEnemy const &src);
    //WeaponEnemy              &operator=(WeaponEnemy const &);
    
    virtual ProjectileEnemy  *fire(vector2 *coord, vector2 *delta_v);
    virtual                 ~WeaponEnemy(void);
};

#endif      /* _WEAPON_BASE_HPP_ */
