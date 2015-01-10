#ifndef     _WINUI_SCREEN_HPP_
# define    _WINUI_SCREEN_HPP_

# include   <iostream>
# include   <ncurses.h>
#include "WinUI.class.hpp"

class       WinUI_screen : public WinUI
{

    protected:

    public:
        WinUI_screen(void);
        WinUI_screen(unsigned int, unsigned int, unsigned int, unsigned int);
        WinUI_screen(WinUI_screen const &src);
        ~WinUI_screen(void);

        WinUI_screen          &operator=(WinUI_screen const &);
        
};

#endif      /* _WINUI_SCREEN_HPP_ */
