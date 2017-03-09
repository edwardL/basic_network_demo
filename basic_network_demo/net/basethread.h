#ifndef BASE_THREAD_H
#define BASE_THREAD_H

#include "../include/pthread.h"
//#pragma comment(lib,"pthreadVC2")

class BaseThread
{
public:
	BaseThread(bool detach = false);
	virtual ~BaseThread();

	int Start();
	int Join();
	bool IsExit() const {return m_exit;}

private:
	virtual void Run() = 0;	// 只需要重写这个虚函数

private:
	pthread_t m_thread;
	pthread_attr_t m_attr;

protected:
	bool m_exit;
	bool m_detach;
	static void* ThreadWorker(void* data);

private:
	BaseThread(const BaseThread &);
	BaseThread& operator=(const BaseThread&);
};


#endif

