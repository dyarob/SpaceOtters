#ifndef OBJCHAIN_CLASS_HPP
# define OBJCHAIN_CLASS_HPP

# include "objlist.class.hpp"

class	objchain : public objlist {
	public:
		objchain(int startFrame, vector2 &startPos, unsigned short number,
				unsigned short delay, unsigned short pattern);
		~objchain();

		int			sf;
		vector2	sp;
		unsigned short	nu;
		unsigned short	F; //period (in frames)
	private:
		objchain();
		unsigned short	pat;
};

#endif //!OBJCHAIN_CLASS_HPP
