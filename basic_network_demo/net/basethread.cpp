#include "basethread.h"
#include <iostream>
#pragma comment(lib,"pthreadVC2")

BaseThread::BaseThread(bool detach)
	:m_exit(false),
	m_detach(detach)
{

}

BaseThread::~BaseThread()
{

}

int BaseThread::Start()
{
	return pthread_create(&m_thread,NULL,ThreadWorker,this);
}

int BaseThread::Join()
{
	m_exit = true;
	return pthread_join(m_thread,NULL);
}

void* BaseThread::ThreadWorker(void* data)
{
	BaseThread* p = static_cast<BaseThread*>(data);
	if(p->m_detach)
	{
		pthread_detach(pthread_self());
	}
	if(!p->m_exit)
	{
		p->Run();
	}
	return NULL;
}
