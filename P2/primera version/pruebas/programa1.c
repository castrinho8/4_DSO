#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/uio.h>

int main(){

	char *str0 = "hello ";
	char *str1 = "world\n";
	char *str2 = "adios\n";

	struct iovec iov[2];
	struct iovec lec[2];
	ssize_t nwritten,nread;
	int file;

	iov[0].iov_base = str0;
	iov[0].iov_len = strlen(str0);
	iov[1].iov_base = str1;
	iov[1].iov_len = strlen(str1);

	printf("",);
}
