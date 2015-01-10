#ifndef     _WEAPON_HPP_
# define    _WEAPON_HPP_

# include   <iostream>

class       Weapon {

    protected:
        unsigned int    _fire_rate;
        unsigned int    _projectile;

    public:
        Weapon(void);
        Weapon(unsigned int, unsigned int);
        Weapon(Weapon const &src);

        Weapon          &operator=(Weapon const &);
        
        unsigned int    getFireRate(void)   const;
        Projectile      &fire(void);
        virtual         ~Weapon(void);
};

#endif      /* _WEAPON_HPP_ */
