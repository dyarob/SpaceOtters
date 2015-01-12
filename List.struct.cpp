#include    "List.struct.hpp"

List	*List::push ( AGameObject *unit, char type)
{
	List	*ret = new List( );
	ret->setType(type);
	ret->u = unit;
	ret->next = this;
	return ( ret );
}

List	*List::delete_one ( List *list, List *to_delete )
{
	List	*save = list;

	if (!(list && to_delete))
		return NULL;

	if ( list == to_delete )
	{
		save = to_delete->next;
		delete list;
		return ( save );
	}
	while ( list )
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

void	List::delete_all ( List *l )
{
	while ( l )
	{
		l = delete_one ( l, l );
	}
}

List::List(void)
	: u(NULL), next(NULL)
{
}

List::List(AGameObject *unit, List *nxt)
	: u(unit), next(nxt), type('i')
{
}

List::List(List const & src)
{
	*this = src;
}

List::~List(void)
{
}

void		List::setType(char type){
	this->type = type;
}

List &		List::operator=(List const & src)
{
	this->u = src.u;
	this->next = src.next;
	return ( *this );
}
