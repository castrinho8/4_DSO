#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
//	setarch `arch` -R
//ret 48

int anotherfunction(char * argument){
	printf("ARGUMENTO: %p\n",&argument);
	printf("ARGUMENTO: %s\n",argument);
	system(argument);
	//exit(0);
}


int funcion1(int p1,int p2){

		int i = 12,file = 1;
		char a[12];

		printf("Introduzca la entrada:\n");
		scanf("%s",a);

		if((file = open ("stack.bin", O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1){ 
			perror("No se pudo abrir el fichero.\n"); 
			return;
		}                       

		for(i=0;i<100;i++){
		  	if(write(file,&a[i],sizeof(char)) == -1){
				perror("No se pudo escribir en fichero.\n"); 
				return; 
			}
		}

		for (i=0;i<100;i++){
			printf("%p, %i - %c\n",(a+i),i,a[i]);
		}

		for (i=0;i<100;i+=4){
			printf("%p, %i - %02X%02X%02X%02X - %c%c%c%c\n",(a+i),i,(unsigned char) a[i+3],(unsigned char) a[i+2], (unsigned char) a[i+1], (unsigned char) a[i], a[i+3],a[i+2],a[i+1],a[i]);
		}

		close(file);
}


int main(int argc,char *argv[]){

	printf("Inicio\n");
	funcion1(3,3);
	printf("NOOO\n");
	//et:printf("%p\n",&&et);
	printf("FIIIN\n");
}










