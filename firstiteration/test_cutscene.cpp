#include "Cutscene.class.hpp"
#include "CONST.h"

int		main( void )
{
	initscr();
	refresh();
	WinUI_dialogBox		dbox(120, 5, 10, 5);
	dbox.fixeDialog("coucou", 1, 1);
	getch();
	return ( 0 );
}
