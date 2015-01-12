#ifndef                 _LEVEL_HPP_
# define                _LEVEL_HPP_

# include				"WinUI_dialogBox.class.hpp"
# include				"AsteroidField.class.hpp"
# include				"CONST.h"

class                   Level
{
    protected:
        Level(void);

    public:
        Level( std::string nam, int ab_speed );
        Level(Level const & src);
        virtual ~Level();
        
        Level   &operator=(Level const &);

		std::string	name;
		AsteroidField	*af;
		void	init( WinUI_dialogBox *db );
        
};

#endif                  /* !_LEVEL_HPP_ */
