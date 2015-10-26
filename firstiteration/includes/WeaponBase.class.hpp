#ifndef     _WEAPON_BASE_HPP_
# define    _WEAPON_BASE_HPP_

# include   <iostream>
# include	"Weapon.class.hpp"
# include   "WeaponBase.class.hpp"
# include   "ProjectileBase.class.hpp"

class       WeaponBase : public Weapon {

protected:
    unsigned int    _fire_rate;

public:
    WeaponBase(void);
    //WeaponBase(WeaponBase const &src);
    //WeaponBase              &operator=(WeaponBase const &);
    
    virtual ProjectileBase  *fire(vector2 *coord, vector2 *delta_v);
    virtual                 ~WeaponBase(void);
};

#endif      /* _WEAPON_BASE_HPP_ */
