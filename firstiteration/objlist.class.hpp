#ifndef OBJLIST_CLASS_HPP
# define OBJLIST_CLASS_HPP

# include <list>
# include "vector2.class.hpp"
# include "AGameObject.class.hpp"

class	AGameObject;

class	objlist : public std::list<AGameObject*> {
	public:
		objlist();
		~objlist();

		std::ostream	&printTo(std::ostream &o) const;
		void	clean();
		void	clear();
		void	moveAll(int const currentFrame);
		void	collisions();

		bool	isOccupied(vector2 const &pos);
		bool	isOccupied(int x, int y);

		//static void		rmOne(objlist::iterator it);
};

std::ostream	&operator<<(std::ostream &o, objlist const &lgo);

#endif //!OBJLIST_CLASS_HPP
