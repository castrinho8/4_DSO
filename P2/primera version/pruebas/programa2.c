#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/uio.h>

//para ver lo que hace strcat en el stack
//machaca lo que hay debajo del array str0
int main(){

	int i;
	char *str0 = "hello";
	char *str1 = "world";

		for (i=0;i<100;i++){
			printf("%p, %i - %c\n",(str0+i),i,str0[i]);
		}
	
	strcat(str0,str1);	

		for (i=0;i<100;i++){
			printf("%p, %i - %c\n",(str0+i),i,str0[i]);
		}
	
}
