#ifndef                 _PROJECTILES_HPP_
# define                _PROJECTILES_HPP_

# include <iostream>
# include "AGameObject.class.hpp"
# include "vector2.class.hpp"

class                   Projectile : public AGameObject {
    protected:
        Projectile(void);
		static Skin*	skin;

    public:
        Projectile(unsigned int, unsigned int, vector2, vector2);
        Projectile(Projectile const & src);
        virtual ~Projectile();
        
        Projectile      &operator=(Projectile const &);
        
		void			update( void );
        unsigned int    getDamage(void) const;
};

#endif                  /* !_PROJECTILES_HPP_ */
