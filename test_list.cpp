#include "List.struct.hpp"
#include "EnemyBase.class.hpp"
#include <iostream>
#include <string>

int		main( void )
{
	EnemyBase	*truc = new EnemyBase( *(new Vector2D(3, 5)), *(new Vector2D(1, 0)) );
	List		*test = new List ( (AUnit*)truc );
	(void)test;
	/*
	AUnit	*a = new AUnit(1, 2, 3, 4, 5, NULL, NULL, NULL);
	List	*test = new List(bleh);
	List	*voila = new List(a, test);
	voila = voila->push(bluh);
	delete ( voila );
	while (voila)
	{
		std::cout << *voila->o << std::endl;
		voila = voila->next;
	}
	*/
	return (0);
}
