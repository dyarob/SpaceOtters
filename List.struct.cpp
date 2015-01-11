#include    "List.struct.hpp"

List	*List::push ( AGameObject *unit )
{
	List	*ret = new List( );
	ret->u = unit;
	ret->next = this;
	return ( ret );
}

void	List::save_all ( List *list ) {
	List	*ptr = list;
	std::ofstream o("log", std::ios::app);

	while ( ptr ) {

		o << "_id :" << ptr->u->getId() << std::endl
		<< "_height :" << ptr->u->getHeight() << std::endl
		<< "_width :" << ptr->u->getWidth() << std::endl
		<< "_hp :" << ptr->u->getHp() << std::endl
		<< "_hp_max :" << ptr->u->getHpMax() << std::endl
		<< "_coord :" << ptr->u->getCoord().getX() << " <> " << ptr->u->getCoord().getY() << std::endl
		<< "_delta_v :" << ptr->u->getDeltaV().getX() << " <> "  << ptr->u->getDeltaV().getY() << std::endl
		<< std::endl;

		ptr = ptr->next;
	}
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
	: u(NULL), next(NULL)
{
}

List::List(AGameObject *unit, List *nxt)
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
