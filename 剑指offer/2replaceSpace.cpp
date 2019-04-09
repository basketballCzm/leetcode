/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
  public:
	//从左向右遍历，从右向左进行移动
	void replaceSpace(char *str, int length) {
		for (int i = 0; i < length; i++) {
			if (' ' == str[i]) {
				for (int j = length - 1; j > i; j--) {
					str[j + 2] = str[j];
				}
				str[i] = '%';
				str[i + 1] = '2';
				str[i + 2] = '0';
				length += 2;
			}
		}
	}
};

struct sockaddr_in *sock = ( struct sockaddr_in*)&from;
int port = ntohs(sock->sin_port);
#ifdef __MINGW32__  //windows上打印方式
printf("ip:port  %s : %d", inet_ntoa(sock->sin_addr), port);
#else              //linux上打印方式
struct in_addr in  = sock->sin_addr;
char str[INET_ADDRSTRLEN];   //INET_ADDRSTRLEN这个宏系统默认定义 16
//成功的话此时IP地址保存在str字符串中。
inet_ntop(AF_INET, &in, str, sizeof(str));
printf("ip:port  %s : %d", str, port);
