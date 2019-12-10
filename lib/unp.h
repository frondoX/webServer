#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>

#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif

#ifdef HAVE_SYS_SYSCTL_H
#include <sys/sysctl.h>
#endif

#ifdef HAVE_POLL_H
#include <poll.h>
#endif

#ifdef HAVE_SYS_EVENT_H
#include <sys/event.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif

#ifdef HAVE_SYS_FILIO_H
#include <sys/filio.h>
#endif

#ifdef HAVE_SYS_SOCKIO_H
#include <sys/sockio.h>
#endif

#ifdef HAVE_PTHREAD_H
#include <pthread.h>
#endif

#ifdef HAVE_NET_IF_DL_H
#include <net/if_dl.h>
#endif

#ifdef __osf__
#undef recv
#undef send
#define recv(a,b,c,d) recvfrom(a,b,c,d,0,0)
#define send(a,b,c,d) sendto(a,b,c,d,0,0)
#endif

#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif

#ifndef SHUT_RD
#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2
#endif

#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN 16
#endif

#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 46
#endif

#if 0
#ifndef HAVE_BZERO
#define bzero(ptr,n) memset(ptr, 0, n)
#endif
#endif

#ifndef HAVE_GETHOSTBYNAME2
#define gethostbyname2(host, family) gethostbyname((host))
#endif

#if 0
struct inp_ip_pktinfo{
	struct in_addr ipi_addr;
	int ipi_ifindex;
};
#endif

#ifndef CMSG_LEN
#define CMSG_LEN(size) (sizeof(struct cmsghdr) + (size))
#endif

#ifndef CMSG_SPACE
#define CMSG_SPACE(size) (sizeof(struct cmsghdr) + (size))
#endif


#ifndef SUN_LEN
#define SUN_LEN(su) \
	(sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
#endif

#ifndef AF_LOCAL
#define AF_LOCAL AF_UNIX
#endif

#ifndef PF_LOCAL
#define PF_LOCAL PF_UNIX
#endif

#ifndef INFTIM
#define INFTIM (-1)
#ifdef HAVE_POLL_H
#define INFTIM_UNPH
#endif
#endif

#define LISTENQ 1024
#define MAXLINE 4096
#define BUFFSIZE 8192

#define SERV_PORT 9877
#define SERV_PORT_STR "9877"
#define UNIXSTR_PATH "/tmp/unix.str"
#define UNIXDG_PATH "/tmp/unix.dg"

#define SA struct sockaddr

#define HAVE_STRUCT_SOCKADDR_STORAGE
#ifndef HAVE_STRUCT_SOCKADDR_STORAGE
#define __SS_MAXSIZE 128
#define __SS_ALIGNSIZE (sizeof(int64_t))
#ifdef HAVE_SOCKADDR_SA_LEN
#define __SS_PAD1SIZE (__SS_ALIGNSIZE - sizeof(u_char) - sizeof(sa_family_t))
#else
#define __SS_PAD1SIZE (__SS_ALIGNSIZE - sizeof(sa_family_t))
#endif
#define __SS_PAD2SIZE (__SS_MAXSIZE - 2 * __SS_ALIGNSIZE)

struct sockaddr_storage
{
#ifdef HAVE_SOCKADDR_SA_LEN
	u_char ss_len;
#endif
	sa_family_t ss_family;
	char __ss_pad1[__SS_PAD1SIZE];
	int64_t __ss_align;
	char __ss_pad2[__SS_PAD2SIZE];
};
#endif

#define FILE_MODE (S_IRUSR | S_UWUSR | S_IRGRP | S_IROTH)

#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#if 0
#ifndef HAVE_IF_NAMEINDEX_STRUCT
struct if_nameindex{
	unsigned int if_index;
	char *if_name;
};
#endif
#endif

#if 0
#ifndef HAVE_TIMESPEC_STRUCT
struct timespec{
	time_t tv_sec;
	long tv_nsec;
};
#endif
#endif


ssize_t readn(int filedes, void *buff, size_t nbytes);
ssize_t written(int fileds, const void *buff, size_t nbytes);
ssize_t readline(int filedes, void *buff, size_t maxlen);
