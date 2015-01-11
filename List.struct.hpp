#ifndef     _LIST_STRUCT_HPP_
# define    _LIST_STRUCT_HPP_

# include   <iostream>
# include   <ncurses.h>
# include	"AGameObject.class.hpp"

class       List {

    public:
        List(void);
        List( AGameObject* unit, List *nxt = NULL);
        List(List const &src);
        ~List(void);

        List          &operator=(List const &);

		AGameObject	*u;
		List	*next;

		List	*push ( AGameObject *unit );
		List	*delete_one ( List *list, List *to_delete );
		//void	delete_all ();
};

#endif      /* _LIST_STRUCT_HPP_ */
