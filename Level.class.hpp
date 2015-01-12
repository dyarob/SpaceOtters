#ifndef                 _LEVEL_HPP_
# define                _LEVEL_HPP_

# include				"AsteroidField.class.hpp"

# define H_MAP 30
# define W_SCREEN 120

class                   Level
{
    protected:
        Level(void);

    public:
        Level( int ab_speed );
        Level(Level const & src);
        virtual ~Level();
        
        Level   &operator=(Level const &);

		AsteroidField	*af;
        
};

#endif                  /* !_LEVEL_HPP_ */
