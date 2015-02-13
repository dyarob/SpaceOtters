#ifndef OBJLIST_CLASS_HPP
# define OBJLIST_CLASS_HPP

# include <list>
# include "AGameObject.class.hpp"

class	objlist : public std::list<AGameObject*> {
	public:
		objlist();
		~objlist();

		std::ostream	&printTo(std::ostream &o) const;
};

std::ostream	&operator<<(std::ostream &o, objlist const &lgo);

#endif //!OBJLIST_CLASS_HPP
