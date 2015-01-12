#ifndef                 _BLOCK_BASE_HPP_
# define                _BLOCK_BASE_HPP_

# include               <iostream>
# include               "Block.class.hpp"
# include               "Vector2D.class.hpp"

class                   BlockBase : public Block {
    private:
        BlockBase(void);
		static Skin* skin;

    public:
        BlockBase(Vector2D &, int);
        BlockBase(BlockBase const & src);
        
        BlockBase      &operator=(BlockBase const &src);
        
        virtual ~BlockBase(void);
};

#endif                  /* !_BLOCK_BASE_HPP_ */
