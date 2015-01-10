#ifndef     _AUNIT_HPP_
# define    _AUNIT_HPP_

# include   <iostream>
# include   "Vector2D.class.hpp"
# include   "Weapon.class.hpp"

class       AUnit {

private:
    AUnit(void);

protected:
    unsigned int    _id;
    unsigned int    _height;
    unsigned int    _width;
    unsigned int    _hp;
    unsigned int    _hp_max;
    Weapon          &_weapon;
    Vector2D        &_coord;
    Vector2D        &_delta_v;

public:
    static unsigned int _cur_id;
    AUnit(unsigned int height, unsigned int width, int hp, int hp_max,
        Weapon &weapon, Vector2D &coord, Vector2D &delta_v);
    AUnit(AUnit const & src);

    AUnit           &operator=(AUnit const &);

    unsigned int    getId(void)             const;
    unsigned int    getHeight(void)         const;
    unsigned int    getWidth(void)          const;
    unsigned int    getHp(void)             const;
    unsigned int    getHpMax(void)          const;
    Weapon  const   &getWeapon(void)        const;
    Vector2D const  &getCoord(void)         const;
    Vector2D const  &getDeltaV(void)        const;
    virtual void    shoot(Weapon const &)   const = 0;

    void            move(Vector2D &delta_v);
    void            setDeltaV(Vector2D &delta_v);
    virtual         ~AUnit(void);
};

#endif      /* !_AUNIT_HPP_ */
