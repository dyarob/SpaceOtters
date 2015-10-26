#ifndef                 _PROJECTILE_BASE_HPP_
# define                _PROJECTILE_BASE_HPP_

# include               <iostream>
# include               "Projectile.class.hpp"
# include               "vector2.class.hpp"

class                   ProjectileBase : public Projectile {
    private:
        ProjectileBase(void);

    public:
        ProjectileBase(vector2 &, vector2 &);
        //ProjectileBase(ProjectileBase const & src);
        //ProjectileBase      &operator=(ProjectileBase const &src);
        
        virtual ~ProjectileBase(void);
};

#endif                  /* !_PROJECTILE_BASE_HPP_ */
