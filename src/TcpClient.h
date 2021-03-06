/*
 *  CopyRight  2014 , bingyu.song   All Right Reserved
    I believe  Spring brother
 */

#ifndef     _TCP_CLIENT_H_
#define     _TCP_SERVER_H_

#include "Connection.h"
#include <string>
#include "TinyDefine.h"

class EventLoop;
class Connector;
struct sockaddr_in;

class    TcpClient
{
public:
    TcpClient( EventLoop* loop,  const char* ip, int port );
    ~TcpClient();
public:
    void init( );
    void run();
    void connect();
    void stop();
    void disconnect();
    void onNewConn( int fd, struct sockaddr_in& addr  );
    void onRemoveConnection( Connection* conn );
    void onConn();

    void    setReadCallBack( const ReadCallBack& cb ) { readCallBack_ = cb; }
    void    setCloseCallBack( const CloseCallBack& cb ) { closeCallBack_ = cb; }
    void    setConnCallBack( const ConnCallBack& cb ) { connCallBack_ = cb; }

private:

    EventLoop*  loop_;
    std::string serverIp_;
    int         serverPort_;

    bool        isConnect_;
    Connector*  connector_;
    Connection* conn_;

    ReadCallBack    readCallBack_;
    CloseCallBack   closeCallBack_;
    ConnCallBack    connCallBack_;

};

#endif  //     _TCP_SERVER_H_




