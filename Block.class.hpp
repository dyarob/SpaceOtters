#ifndef                 _BLOCK_HPP_
# define                _BLOCK_HPP_

# include               <iostream>
# include                "AGameObject.class.hpp"
# define				B_SPEED -2

class                   Block : public AGameObject {
    protected:
		static Skin		*skin;
		int				speed;
        Block(void);

    public:
        Block( unsigned int, unsigned int, Vector2D &, int);
        Block(Block const & src);
        virtual ~Block();
        
        Block      &operator=(Block const &);
        
		void			update( void );
};

#endif                  /* !_BLOCK_HPP_ */
