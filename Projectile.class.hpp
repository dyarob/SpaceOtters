#ifndef                 _PROJECTILES_HPP_
# define                _PROJECTILES_HPP_

# include               <iostream>

class                   Projectile {
    protected:
        unsigned int    _damage;
        unsigned int    _speed;
        unsigned int    _width;
        unsigned int    _height;
        Vector2D        &_coord;
        Vector2D        &_delta_v;

    public:
        Projectile(void);
        Projectile(unsigned int, unsigned int, unsigned int, unsigned int, Vector2D &, Vector2D &);
        Projectile(Projectile const & src);
        
        Projectile      &operator=(Projectile const &);
        
        unsigned int    getDamage(void)     const;
        unsigned int    getSpeed(void)      const;
        unsigned int    getWidth(void)      const;
        unsigned int    getHeight(void)     const;
        Vector2D const  &getCoord(void)     const;
        Vector2D const  &getDeltaV(void)    const;
        
        virtual ~Projectile();
};

#endif                  /* !_PROJECTILES_HPP_ */
