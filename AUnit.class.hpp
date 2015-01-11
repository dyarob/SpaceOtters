#ifndef     _AUNIT_HPP_
# define    _AUNIT_HPP_

# include   <iostream>
# include   "AGameObject.class.hpp"
# include   "Weapon.class.hpp"

class       AUnit : public AGameObject {

private:
    AUnit(void);

protected:
    Weapon          &_weapon;

public:
    AUnit(unsigned int height, unsigned int width, int hp, int hp_max,
        Weapon &weapon, Vector2D &coord, Vector2D &delta_v);
    AUnit(AUnit const & src);

    AUnit           &operator=(AUnit const &);

    Weapon  const   &getWeapon(void)        const;
    virtual Projectile    *shoot(void)   const;

    virtual         ~AUnit(void);
};

#endif      /* !_AUNIT_HPP_ */
