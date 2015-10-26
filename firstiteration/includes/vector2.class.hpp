#ifndef VECTOR2_CLASS_HPP
# define VECTOR2_CLASS_HPP

# include <utility> //pair
# include <iostream>

class	vector2 : public std::pair<int, int> {
	public:
		int	&x;
		int	&y;

		vector2(void);
		vector2(int, int);
		~vector2(void);
};

std::ostream	&operator<<(std::ostream &o, vector2 const &v);

#endif
