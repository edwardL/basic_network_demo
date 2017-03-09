#include "basesocket.h"
#include "basethread.h"
#include <vector>

class ServerSocket;

class AcceptThread : public BaseThread
{
public:
	AcceptThread(ServerSocket* server)
		:BaseThread(true)
		,m_server(server){}
	~AcceptThread(){}

public:
	void Run();
private:
	ServerSocket* m_server;
};

class ClientAgentThread : public BaseThread
{
public:
	ClientAgentThread(ServerSocket* server, SOCKET client)
		:BaseThread(true)
		,m_server(server)
		,m_client(client)
	{

	}
public:
	void Run();

private:
	ServerSocket *m_server;
	SOCKET m_client;
};

class ServerSocket : public BaseSocket
{
public:
	ServerSocket(int port);
	virtual ~ServerSocket();

public:
	void Start();
	void Stop();

	void Process();
	void WaitClient();
	void WaitClientMsg(SOCKET client);
	void OnMsgReceive(SOCKET socket, void* data, int length);
	void ClearAgent();
private:
	int m_port;
	bool m_stop;
	
	AcceptThread* m_accept_thread;
	std::vector<ClientAgentThread*> m_client_agent_list;
};