#ifndef                 _PROJECTILE_ENEMY_HPP_
# define                _PROJECTILE_ENEMY_HPP_

# include               <iostream>
# include               "Projectile.class.hpp"
# include               "Vector2D.class.hpp"

class                   ProjectileEnemy : public Projectile {
    private:
        ProjectileEnemy(void);
		static Skin* skin;

    public:
        ProjectileEnemy(Vector2D &, Vector2D &);
        ProjectileEnemy(ProjectileEnemy const & src);
        
        ProjectileEnemy      &operator=(ProjectileEnemy const &src);
        
        virtual ~ProjectileEnemy(void);
};

#endif                  /* !_PROJECTILE_BASE_HPP_ */
