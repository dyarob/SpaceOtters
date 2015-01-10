#ifndef     _WINUI_HPP_
# define    _WINUI_HPP_

# include   <iostream>
# include   <ncurses.h>

class       WinUI {

    protected:
      
		unsigned int 	_width;
		unsigned int 	_height;
        unsigned int    _startX;
        unsigned int    _startY;
		unsigned int    _heightMap;

    public:
        WinUI(void);
        WinUI(unsigned int, unsigned int, unsigned int, unsigned int);
        WinUI(WinUI const &src);
        ~WinUI(void);

        WinUI          &operator=(WinUI const &);
        
        WINDOW          *createWin(void);
        void            destroyWin(void);
        unsigned int    getWidth(void) const;
        unsigned int    getHeight(void) const;
        unsigned int    getStartX(void) const;
        unsigned int    getStartY(void) const;

        WINDOW          *win;
};

#endif      /* _WINUI_HPP_ */
