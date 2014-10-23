/*
 *  CopyRight  2014 , bingyu.song   All Right Reserved
    I believe  Spring brother
 */

#ifndef  _TCP_SERVER_H_
#define  _TCP_SERVER_H_


#include <list>

class  IConnection;
class  Connection;
class  TcpAcceptor;
class  EventLoop;

class  TcpServer
{
public:
     TcpServer( int port = 8888 );
     ~TcpServer( );

public:
    void    run();
private:
    int     init();
public:
    void    onNewConnection( int*  fd, struct sockaddr_in*  addr  );
    void    onRemoveConnection( Connection* conn );
public:
    int     onConnection( Connection* conn );
    void    onRead ( Connection* conn );
    void    onWrite( Connection* conn );
    void    onClose( Connection* conn );
private:
    int                     port_;
    TcpAcceptor*            acceptor_;
    EventLoop*              loop_;
    typedef   std::list<Connection*> ConnectionList;
    ConnectionList          connectionList_;
};

#endif // _TCP_SERVER_H_











