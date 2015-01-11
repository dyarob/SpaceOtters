#ifndef                 _PROJECTILES_HPP_
# define                _PROJECTILES_HPP_

# include               <iostream>
# include                "AGameObject.class.hpp"

class                   Projectile : public AGameObject {
    protected:
        Projectile(void);
        unsigned int    _damage;

    public:
        Projectile(unsigned int, unsigned int, unsigned int, Vector2D &, Vector2D &);
        Projectile(Projectile const & src);
        virtual ~Projectile();
        
        Projectile      &operator=(Projectile const &);
        
        unsigned int    getDamage(void)     const;
		void			update( void );
};

#endif                  /* !_PROJECTILES_HPP_ */
