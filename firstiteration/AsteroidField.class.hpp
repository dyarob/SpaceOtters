#ifndef                 _ASTEROIDFIELD_HPP_
# define                _ASTEROIDFIELD_HPP_

# include				"CONST.h"
# include				"BlockBase.class.hpp"
# include				"vector2.class.hpp"
# include				<stdlib.h> //rand
# include				"objlist.class.hpp"

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

		void	generateBlocks(objlist &units);
        
};

#endif                  /* !_ASTEROIDFIELD_HPP_ */
