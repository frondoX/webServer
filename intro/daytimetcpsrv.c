#include "../lib/unp.h"
#include "../lib/error.c"

int main(int argc, char **argv)
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(9877);

	bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);

	for(; ;)
	{
		connfd = accept(listenfd, (SA*)NULL, NULL);
		ticks = time(NULL);

		snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
		write(connfd, buf, strlen(buf));
		close(connfd);
	}
}
