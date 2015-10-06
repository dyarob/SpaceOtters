#ifndef                 _BLOCK_HPP_
# define                _BLOCK_HPP_

# include				"CONST.h"
# include               <iostream>
# include				"vector2.class.hpp"
# include               "AGameObject.class.hpp"

class                   Block : public AGameObject {
    protected:
		static Skin		*skin;
		int				speed;
        Block(void);

    public:
        Block( unsigned int, unsigned int, vector2, int);
        //Block(Block const & src);
        //Block      &operator=(Block const &);
        virtual ~Block();
        
        
		void			update( void );
};

#endif                  /* !_BLOCK_HPP_ */
