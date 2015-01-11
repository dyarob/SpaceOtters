#ifndef     _WEAPON_HPP_
# define    _WEAPON_HPP_

# include   <iostream>
# include   "Projectile.class.hpp"
# include   "Vector2D.class.hpp"

class       Weapon {

private:
    Weapon(void);

protected:
    unsigned int    _fire_rate;

public:
    Weapon(unsigned int);
    Weapon(Weapon const &src);

    Weapon              &operator=(Weapon const &);
    
    unsigned int        getFireRate(void)       const;

    virtual Projectile  *fire(Vector2D *coord, Vector2D *delta_v);
    virtual             ~Weapon(void);
};

#endif      /* _WEAPON_HPP_ */
