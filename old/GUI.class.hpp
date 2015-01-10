#ifndef     _GUI_HPP_
# define    _GUI_HPP_

# include   <iostream>

class       GUI {

    protected:
		unsigned int const	_witdh;
		unsigned int const	_height;
		unsigned int const	_heightMap;

    public:
        GUI(void);
        //GUI();
        GUI(GUI const &src);

        GUI          &operator=(GUI const &);
        
        unsigned int    getFireRate(void)   const;
        Projectile      &fire(void);
        virtual         ~GUI(void);
};

#endif      /* _GUI_HPP_ */
