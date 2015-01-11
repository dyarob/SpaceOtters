#ifndef     _WINUI_DIALOGBOX_CLASS_HPP_
# define    _WINUI_DIALOGBOX_CLASS_HPP_

# include "WinUI.class.hpp"

class       WinUI_dialogBox : public WinUI {

    protected:


    public:
        WinUI_dialogBox(void);
        WinUI_dialogBox(unsigned int, unsigned int, unsigned int, unsigned int);
        WinUI_dialogBox(WinUI_dialogBox const &src);
        ~WinUI_dialogBox(void);

        WinUI_dialogBox       &operator=(WinUI_dialogBox const &);
        
        void        fixeDialog(std::string, unsigned int, unsigned int);
        void        translateDialog(std::string);
        void        tabInfoDial(std::string *);
};

#endif      /* _WINUI_DIALOGBOX_CLASS_HPP_ */
