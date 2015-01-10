#include    "List.struct.hpp"

List	*List::push ( AUnit *unit )
{
	List	*ret = new List( );
	ret->u = unit;
	ret->next = this;
	return ( ret );
}

List	*List::delete_one ( List *list, List *to_delete )
{
	List	*save = list;

	if ( list == to_delete )
	{
		save = to_delete->next;
		delete list;
		return ( save );
	}
	while ( list->next )
	{
		if ( list->next == to_delete )
		{
			list->next = to_delete->next;
			delete to_delete;
			return ( save );
		}
		list = list->next;
	}
	return ( save );
}

/*
void	List::delete_all ( )
{
	List	*save = this;
	while ( save->next )
	{
		save = delete_one ( this, this );
	}
}
*/

List::List(void)
{
}

List::List(AUnit *unit, List *nxt)
	: u(unit), next(nxt)
{
}

List::List(List const & src)
{
	*this = src;
}

List::~List(void)
{
}

List &		List::operator=(List const & src)
{
	this->u = src.u;
	this->next = src.next;
	return ( *this );
}
