#ifndef                 _PROJECTILES_HPP_
# define                _PROJECTILES_HPP_

# include               <iostream>
# include                "AGameObject.class.hpp"

class                   Projectile : public AGameObject {
    protected:
        Projectile(void);
		static Skin*	skin;

    public:
        Projectile(unsigned int, unsigned int, Vector2D &, Vector2D &);
        Projectile(Projectile const & src);
        virtual ~Projectile();
        
        Projectile      &operator=(Projectile const &);
        
		void			update( void );
        unsigned int    getDamage(void) const;
};

#endif                  /* !_PROJECTILES_HPP_ */
