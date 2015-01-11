#ifndef TIMER_HPP
#define TIMER_HPP

#include <sys/time.h>
#include <unistd.h>

class Timer {

	private	:

		unsigned int	_framerate;
		struct timeval	_createdAt;
		struct timeval	_startAt;
		struct timeval	_endAt;

	public	:

		Timer();
		Timer(unsigned int);
		Timer(Timer const&);
		~Timer();

		Timer& operator=(Timer const&);

		unsigned int	getFramerate() const;
		struct timeval	getCreationTime() const;
		struct timeval	getStart() const;
		struct timeval	getEnd() const;

		void				setFramerate(unsigned int);

		void				start();
		void				stop();
		void				wait();
		unsigned long int	elapsedTime();
};

#endif
