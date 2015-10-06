#ifndef                 _PROJECTILE_SEGV_HPP_
# define                _PROJECTILE_SEGV_HPP_

# include               <iostream>
# include               "Projectile.class.hpp"
# include               "Vector2D.class.hpp"

class                   ProjectileSegv : public Projectile {
    private:
        ProjectileSegv(void);
		static Skin* skin;

    public:
        ProjectileSegv(Vector2D &, Vector2D &);
        ProjectileSegv(ProjectileSegv const & src);
        
        ProjectileSegv      &operator=(ProjectileSegv const &src);
        
        virtual ~ProjectileSegv(void);
};

#endif                  /* !_PROJECTILE_SEGV_HPP_ */
