#ifndef     _AUNIT_HPP_
# define    _AUNIT_HPP_

# include   <iostream>
# include   "Vector2D.class.hpp"
# include   "Weapon.class.hpp"

class       AUnit {

unsigned int        cur_id;

private:
    AUnit(void);

protected:
    unsigned int    _id;
    unsigned int    _speed;
    unsigned int    _height;
    unsigned int    _width;
    unsigned int    _hp;
    unsigned int    _hp_max;
    Weapon          _weapon;

public:
    AUnit(unsigned int, Vector2D &, Vector2D &, unsigned int, unsigned int,
        unsigned int, unsigned int, unsigned int, int, Weapon const &);
    AUnit(AUnit const & src);

    AUnit           &operator=(AUnit const &);

    unsigned int    getId(void)             const;
    unsigned int    getSpeed(void)          const;
    unsigned int    getAcceleration(void)   const;
    unsigned int    getHeight(void)         const;
    unsigned int    getWidth(void)          const;
    unsigned int    getHp(void)             const;
    unsigned int    getHpMax(void)          const;
    Weapon  const   &getWeapon(void)        const;
    Vector2D const  &getCoord(void)         const;
    Vector2D const  &getDeltaV(void)        const;
    virtual void    shoot(Weapon const &)   const = 0;
    virtual         ~AUnit(void);
};

#endif      /* !_AUNIT_HPP_ */
