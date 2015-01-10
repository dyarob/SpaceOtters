#ifndef 	EVENT_CLASS_HPP
# define 	EVENT_CLASS_HPP

# define	FIRSTNODE 0
# define	NULL 0

class		Event{
	private:
		int			_type;
		int			_delay;
		int			_posY;
		Event	*	_next;
		Event	*	_prev;

	public:
		Event();
		Event(int, int, int);
		Event(Event const &);
		Event & operator=(Event const &);
		int		getType() const;
		int		getDelay() const;
		int		getPosY() const;
		void	pushFront(int, int, int);
		void	pushBack(int, int, int);
		~Event();
};

#endif
