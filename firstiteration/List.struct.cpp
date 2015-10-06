#include	"ProjectileEnemy.class.hpp"
#include	"E_Zaz.class.hpp"
#include    "EnemyBase.class.hpp"
#include    "BlockBase.class.hpp"
#include    "ProjectileBase.class.hpp"
#include    "List.struct.hpp"

List	*List::push ( AGameObject *unit, char type)
{
	if (!unit)
		return (this);
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
	if (type == 'm')
		delete (ProjectileEnemy*)u;
	else if (type == 'e')
	{
		if ( u->getWidth() > 1 )
			delete (E_Zaz *)u;
		else
			delete (EnemyBase*)u;
	}
	else if (type == 'p')
		delete (ProjectileBase*)u;
	else if (type == 'a')
		delete (BlockBase*)u;
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
