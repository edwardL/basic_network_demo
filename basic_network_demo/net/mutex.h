#ifndef MUTEX_H
#define MUTEX_H
#include "../include/pthread.h"
class Mutex
{
public:
	Mutex();
	~Mutex();

	void Lock();
	void UnLock();
	void Destroy();

private:
	pthread_mutex_t _lock;
	bool m_destroyed;

	Mutex(const Mutex&){}
	Mutex& operator=(const Mutex&){}
};


#endif