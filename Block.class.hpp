#ifndef                 _BLOCK_HPP_
# define                _BLOCK_HPP_

# include               <iostream>
# include                "AGameObject.class.hpp"
# define				B_SPEED -2

class                   Block : public AGameObject {
    protected:
        Block(void);

    public:
        Block( unsigned int, unsigned int, Vector2D &);
        Block(Block const & src);
        virtual ~Block();
        
        Block      &operator=(Block const &);
        
		void			update( void );
};

#endif                  /* !_BLOCK_HPP_ */
