#ifndef     _LIST_STRUCT_HPP_
# define    _LIST_STRUCT_HPP_

# include   <iostream>
# include   <fstream>
# include   <ncurses.h>
# include	"AGameObject.class.hpp"

class		AGameObject;
class		Player;

class       List {

    public:
		static int		player_dead;
        List(void);
        List( AGameObject* unit, List *nxt = NULL);
        List(List const &src);
        ~List(void);

        List          &operator=(List const &);

		AGameObject	*u;
		List	*next;

   
		List        *push ( AGameObject *unit, char );
        char        type;
		static List	*delete_one ( List *list, List *to_delete );
        void        setType(char);

		static void	delete_all ( List *l );
};

#endif      /* _LIST_STRUCT_HPP_ */
