/*
 *  CopyRight  2014 , bingyu.song   All Right Reserved
    I believe  Spring brother
 */
#ifndef _SOCKET_HELPER_H_
#define _SOCKET_HELPER_H_


struct sockaddr_in;

//socket op wraper.
class   SocketHelper
{
public:
    static  int     createNonBlockingSocket( );
    int     bind( int fd, const struct sockaddr_in*  addr );
    int     listen( int fd );
    //TODO: accept4 ?
    int     accept( int fd,struct  sockaddr_in* addr );
    int     connect(int fd, const struct sockaddr_in* addr );
    int     read( int fd, char* buf, int len );
    int     write( int fd, char* buf, int len );
    //TODO  readv writev
    int     readv(int fd, const struct iovec* iov, int iovcnt );

    int     close( int fd );
    int     shutdown( int fd );

    //set socket
    int     setTcpNoDelay( int fd,bool isOpen );
    int     setReuseAddr ( int fd,bool isOPen );
    int     setReusePort ( int fd,bool isOPen );
    int     setKeepAlive ( int fd,bool isOpen );

    int     getSocketError( int fd );
    struct sockaddr_in   getLocalAddr( int fd );
    struct sockaddr_in  getPeerAddr( int fd );
    bool    isSelfConnect( int fd );
private:
    int     setSocketOpt( int fd,int optname, int& optval );
private:
    int fd_;
};

#endif // _SOCKET_HELPER_H_



