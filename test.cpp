#include "WinUI.class.hpp"
#include "WinUI_dialogBox.class.hpp"
#include "WinUI_screen.class.hpp"
#include "EnemyBase.class.hpp"
#include "List.struct.hpp"
#include "AUnit.class.hpp"
#include <unistd.h>


int main( void ){

	WinUI_dialogBox *BoxHead = new WinUI_dialogBox(120, 3, 1, 0);
	WinUI_screen *game = new WinUI_screen(120, 30, 4, 0);
	WinUI_dialogBox *BoxText = new WinUI_dialogBox(120, 5, 34, 0);


	EnemyBase	*truc = new EnemyBase( *(new Vector2D(3, 5)), *(new Vector2D(1, 0)) );
	EnemyBase	*truc2 = new EnemyBase( *(new Vector2D(4, 6)), *(new Vector2D(1, 0)) );
	EnemyBase	*truc3 = new EnemyBase( *(new Vector2D(5, 7)), *(new Vector2D(1, 0)) );
	List		*test = new List ( (AUnit*)truc );

	test = test->push(truc2);
	test = test->push(truc3);
	while (1){
		game->update(test);
		BoxText->translateDialog("Bonjour les gens!");
		BoxHead->fixeDialog(WinUI::keyEvent());
		usleep(2000);
	}
	game->destroyWin();
	BoxHead->destroyWin();
	BoxText->destroyWin();


	endwin();
	return 0;
}
