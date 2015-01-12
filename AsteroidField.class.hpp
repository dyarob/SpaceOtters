#ifndef                 _ASTEROIDFIELD_HPP_
# define                _ASTEROIDFIELD_HPP_

# include				"BlockBase.class.hpp"
# include				"CONST.h"

class                   AsteroidField
{
    protected:
        AsteroidField(void);
		int				b_speed;

    public:
        AsteroidField( int ab_speed );
        AsteroidField(AsteroidField const & src);
        virtual ~AsteroidField();
        
        AsteroidField   &operator=(AsteroidField const &);

		virtual void	generateBlocks( List **units );
        
};

#endif                  /* !_ASTEROIDFIELD_HPP_ */
