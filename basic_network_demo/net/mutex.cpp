#include "mutex.h"

Mutex::Mutex()
	:m_destroyed(false)
{
	pthread_mutex_init(&_lock,NULL);
}

Mutex::~Mutex()
{
	Destroy();
}

void Mutex::Destroy()
{
	if(!m_destroyed)
	{
		pthread_mutex_destroy(&_lock);
		m_destroyed = true;
	}
}

void Mutex::Lock()
{
	pthread_mutex_lock(&_lock);
}

void Mutex::UnLock()
{
	pthread_mutex_unlock(&_lock);
}

