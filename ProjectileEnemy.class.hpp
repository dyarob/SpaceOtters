#ifndef                 _PROJECTILE_ENEMY_HPP_
# define                _PROJECTILE_ENEMY_HPP_

# include               <iostream>
# include               "Projectile.class.hpp"
# include               "vector2.class.hpp"

class                   ProjectileEnemy : public Projectile {
    private:
        ProjectileEnemy(void);
		static Skin* skin;

    public:
        ProjectileEnemy(vector2 &, vector2 &);
        //ProjectileEnemy(ProjectileEnemy const & src);
        //ProjectileEnemy      &operator=(ProjectileEnemy const &src);
        
        virtual ~ProjectileEnemy(void);
};

#endif                  /* !_PROJECTILE_BASE_HPP_ */
