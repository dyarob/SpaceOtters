#ifndef     _ENEMY_BASE_HPP_
# define    _ENEMY_BASE_HPP_

# include   <iostream>
# include   "AUnit.class.hpp"
# include   "Vector2D.class.hpp"
# include   "WeaponEnemy.class.hpp"

class       EnemyBase : public AUnit {

private:
    EnemyBase(void);
	static Skin* skin;

public:
    EnemyBase(Vector2D &coord, Vector2D &delta_v, int pattern);
    EnemyBase(EnemyBase const & src);

    EnemyBase           &operator=(EnemyBase const &);

    WeaponEnemy          &getWeapon(void);

    Projectile    *shoot(void)   const;
    ~EnemyBase();
};

#endif      /* !_ENEMY_BASE_HPP_ */

