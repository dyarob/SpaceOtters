#ifndef     _WEAPON_HPP_
# define    _WEAPON_HPP_

# include   <iostream>
#include    "Projectile.class.hpp"

class       Weapon {

private:
    Weapon(void);

protected:
    unsigned int    _fire_rate;
    Projectile      &_projectile;

public:
    Weapon(unsigned int, Projectile &projectile);
    Weapon(Weapon const &src);

    Weapon          &operator=(Weapon const &);
    
    unsigned int    getFireRate(void)       const;
    Projectile      &getProjectile(void)    const;

    Projectile      &fire(void);
    virtual         ~Weapon(void);
};

#endif      /* _WEAPON_HPP_ */
