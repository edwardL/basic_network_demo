#ifndef SOCKET_BASE_H
#define SOCKET_BASE_H

// win ∫Õ linux ∆ΩÃ®≤Ó“Ï
#ifdef WIN32
	#include <WinSock2.h>
	#pragma comment(lib,"Wsock32.lib")
	typedef int ADDR_LEN;
#else
	#include<netdb.h>
	#include<unistd.h>
	#include<sys/socket.h>
	#include<pthread.h>
	#include<sys/types.h>
	#include<arpa/inet.h>
	#include<netinet/in.h>

	typedef int SOCKET
	typedef struct sockaddr_in SOCKADDR_IN
	typedef struct sockaddr SOCKADDR
	typedef socklen_t ADDR_LEN
	#define SOCKET_ERROR -1
	#define INVALID_SOCKET -1
#endif

	void socket_init();
	void socket_clean();
	void close_socket(SOCKET socket);

class BaseSocket
{
public:
	BaseSocket();
	virtual ~BaseSocket();

protected:
	void CloseSocket();
	bool SendTo(SOCKET dest, void* data, int length);

protected:
	static const int MAX_MSG_LENGTH = 1024;
	SOCKET m_socket;
};

#endif


