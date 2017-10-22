#include "head4sock.h"

ssize_t Write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t retval = write(fildes, buf, nbyte);
	if(retval == -1)
	{
		perror("write() error");
	}

	return retval;
}

ssize_t Read(int fildes, void *buf, size_t nbyte)
{
	return read(fildes, buf, nbyte);
}

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	return bind(sockfd, addr, addrlen);
}

int Listen(int sockfd, int backlog)
{
	return listen(sockfd, backlog);
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
	return accept(sockfd, addr, addrlen);
}

int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	return connect(sockfd, addr, addrlen);
}

int Socket(int domain, int type, int protocol)
{
	int sockfd = socket(domain, type, protocol);
	if(sockfd == -1)
	{
		perror("socket() error");
	}

	return sockfd;
}

int Setsockopt(int sockfd, int level, int optname,
	       const void *optval, socklen_t optlen)
{
	int retval = setsockopt(sockfd, level, optname, optval, optlen);
	if(retval == -1)
	{
		perror("setsockopt() error");
	}

	return retval;
}

int Select(int nfds, fd_set *readfds, fd_set *writefds,
	   fd_set *exceptfds, struct timeval *timeout)
{
	return select(nfds, readfds, writefds, exceptfds, timeout);
}
