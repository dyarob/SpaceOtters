#ifndef                 _PROJECTILE_BASE_HPP_
# define                _PROJECTILE_BASE_HPP_

# include               <iostream>
# include               "Projectile.class.hpp"
# include               "Vector2D.class.hpp"

class                   ProjectileBase : public Projectile {
    private:
        ProjectileBase(void);

    public:
        ProjectileBase(Vector2D &, Vector2D &);
        ProjectileBase(ProjectileBase const & src);
        
        ProjectileBase      &operator=(ProjectileBase const &src);
        
        virtual ~ProjectileBase(void);
};

#endif                  /* !_PROJECTILE_BASE_HPP_ */
