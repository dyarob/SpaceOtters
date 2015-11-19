#ifndef WINDOW
# define WINDOW

class		Window {

	public:
							Window();
	virtual			~Window();
	virtual int	update(unsigned const currFrame);
};

#endif
