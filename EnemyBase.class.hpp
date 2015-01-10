#ifndef     _ENEMY_BASE_HPP_
# define    _ENEMY_BASE_HPP_

# include   <iostream>
# include   "AUnit.class.hpp"
# include   "Vector2D.class.hpp"
# include   "WeaponBase.class.hpp"

class       EnemyBase : public AUnit {

private:
    EnemyBase(void);

public:
    EnemyBase(Vector2D &coord, Vector2D &delta_v);
    EnemyBase(EnemyBase const & src);

    EnemyBase           &operator=(EnemyBase const &);

    WeaponBase          &getWeapon(void);

    void    shoot(Weapon const &)   const;
    ~EnemyBase();
};

#endif      /* !_ENEMY_BASE_HPP_ */

