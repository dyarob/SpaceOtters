#include "Timer.class.hpp"

Timer::Timer()
	: _framerate(0),
	_createdAt(),
	_startAt(),
	_endAt()
{
	gettimeofday(&_createdAt, NULL);
}

Timer::Timer(unsigned int framerate)
	: _framerate(framerate),
	_createdAt(),
	_startAt(),
	_endAt()
{
	gettimeofday(&_createdAt, NULL);
}

Timer::Timer(Timer const& copy)
{
	_createdAt = copy.getCreationTime();
	_framerate = copy.getFramerate();
	_startAt = copy.getStart();
	_endAt = copy.getEnd();
}

Timer::~Timer() {}

Timer& Timer::operator=(Timer const& rhs)
{
	_createdAt = rhs.getCreationTime();
	_framerate = rhs.getFramerate();
	_startAt = rhs.getStart();
	_endAt = rhs.getEnd();
	return *this;
}

unsigned int	Timer::getFramerate() const 	{ return _framerate; }
struct timeval	Timer::getCreationTime() const	{ return _createdAt; }
struct timeval	Timer::getStart() const		{ return _startAt; }
struct timeval	Timer::getEnd() const			{ return _endAt; }

void	Timer::setFramerate(unsigned int framerate)
{
	_framerate = framerate;
}

void	Timer::start()
{
	gettimeofday(&_startAt, NULL);
}

void	Timer::stop()
{
	gettimeofday(&_endAt, NULL);
}

void	Timer::wait()
{
	long mtime, sec, usec;

	sec = _endAt.tv_sec - _startAt.tv_sec;
	usec = _endAt.tv_usec - _startAt.tv_usec;
	mtime = sec * 1000000 + usec;
	if (mtime < CLOCKS_PER_SEC / _framerate)
		usleep(CLOCKS_PER_SEC / _framerate - mtime);
}

unsigned long int	Timer::elapsedTime()
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - _createdAt.tv_sec) * 1000000 + (now.tv_usec - _createdAt.tv_usec));
}
