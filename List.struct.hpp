#ifndef     _LIST_STRUCT_HPP_
# define    _LIST_STRUCT_HPP_

# include   <iostream>
# include   <ncurses.h>
# include	"AUnit.class.hpp"

class       List {

    public:
        List(void);
        List( AUnit* unit, List *nxt = NULL);
        List(List const &src);
        ~List(void);

        List          &operator=(List const &);

		AUnit	*u;
		List	*next;

		List	*push ( AUnit *unit );
		List	*delete_one ( List *list, List *to_delete );
		//void	delete_all ();
};

#endif      /* _LIST_STRUCT_HPP_ */
