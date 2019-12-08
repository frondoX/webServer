/********************************************
* webServer 实现简单的web服务，静态的文件请求
* get，post方法。
* athor: frondo
* date: 2019/12/08
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <socket.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <strings.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/wait.h>


void build_server(void);
void parse_request(const char* request);
void act_request(void);
