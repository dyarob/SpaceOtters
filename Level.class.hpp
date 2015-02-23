#ifndef                 _LEVEL_HPP_
# define                _LEVEL_HPP_

# include				"WinUI_dialogBox.class.hpp"
# include				"AsteroidField.class.hpp"
# include				"CONST.h"

class                   Level
{
    private:
        Level(void);


    public:
		std::string		name;
		AsteroidField	*af;

        ~Level();
        Level(std::string nam, int ab_speed);
        Level(Level const & src);
        Level   &operator=(Level const &);

		void	init(WinUI_dialogBox *db);


		static short	id;
		static std::vector<Level*>	lvls;

		static void	lvlsInit();
		static void	update(objlist &objects);
};

#endif                  /* !_LEVEL_HPP_ */
