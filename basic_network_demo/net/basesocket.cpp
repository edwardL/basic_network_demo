#include "basesocket.h"
#include <stdio.h>
#include <string.h>

void socket_init()
{
	#ifdef WIN32
		WSADATA wsd;
		WSAStartup(MAKEWORD(2,2),&wsd);
	#endif
}

void socket_clean()
{
	#ifdef WIN32
		WSACleanup();
	#endif
}

void close_socket(SOCKET socket)
{
	#ifdef WIN32
		closesocket(socket);
	#else
		close(socket);
	#endif
}

BaseSocket::BaseSocket()
	:m_socket(INVALID_SOCKET)
{
	m_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(INVALID_SOCKET == m_socket)
	{
		throw "INVALID SOCKET";
	}
}

BaseSocket::~BaseSocket()
{
	CloseSocket();
}

void BaseSocket::CloseSocket()
{
	if(INVALID_SOCKET != m_socket)
	{
		close_socket(m_socket);
	}
	m_socket = INVALID_SOCKET;
}

bool BaseSocket::SendTo(SOCKET dest, void* data, int length)
{
	if(0 == data)
	{
		return false;
	}
	char buff[1024] = "";
	int pack_size = length + 4;
	memcpy(buff,&pack_size,4);
	memcpy(buff+4,data,length);
	int ret = send(dest,buff,pack_size,0);
	if(SOCKET_ERROR == ret)
	{
		return false;
	}
	return true;
}

