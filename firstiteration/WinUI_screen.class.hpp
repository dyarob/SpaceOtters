#ifndef     _WINUI_SCREEN_HPP_
# define    _WINUI_SCREEN_HPP_

# include   <iostream>
# include	"WinUI.class.hpp"
# include	"AGameObject.class.hpp"
# include	"Player.class.hpp"
# include   "vector2.class.hpp"
# include	<list>

class       WinUI_screen : public WinUI {
    public:
		void	draw ( AGameObject* const &u ) const;
		void	draw_all ( std::list<AGameObject*> const &l ) const;
		void	update ( std::list<AGameObject*> &l );

        WinUI_screen(void);
        WinUI_screen(unsigned int, unsigned int, unsigned int, unsigned int);
        ~WinUI_screen(void);
        //WinUI_screen(WinUI_screen const &src);
        //WinUI_screen          &operator=(WinUI_screen const &);
};

#endif      /* _WINUI_SCREEN_HPP_ */
