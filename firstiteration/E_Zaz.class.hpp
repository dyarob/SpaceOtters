#ifndef     _E_ZAZ_HPP_
# define    _E_ZAZ_HPP_

# include   <iostream>
# include   "AUnit.class.hpp"
# include   "Vector2D.class.hpp"
# include   "WeaponEnemy.class.hpp"

class       E_Zaz : public AUnit {

private:
    E_Zaz(void);
	//static Skin* skin;

public:
    E_Zaz(Vector2D &coord, Vector2D &delta_v, int pattern);
    E_Zaz(E_Zaz const & src);

    E_Zaz           &operator=(E_Zaz const &);

    WeaponEnemy          &getWeapon(void);
	static char	img[28][43];

    Projectile    *shoot(void)   const;
    ~E_Zaz();
};

#endif      /* !_E_ZAZ_HPP_ */

