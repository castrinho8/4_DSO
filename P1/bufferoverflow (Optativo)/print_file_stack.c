/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa que imprime el fichero "stack.txt"

*/
#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(){
	int i = 0, file;
	char a[100];

	printf("IMPRIMIENDO FICHERO STACK.TXT:\n");

	if((file = open("stack.bin", O_RDONLY, 0777)) == -1){ 
		perror("No se pudo abrir el fichero.\n"); 
		return;
	}        

	for(i=0;i<100;i++){
		if(read(file,&a[i],sizeof(char)) == -1){
			perror("No se pudo escribir en fichero.\n"); 
			return; 
		}
	}

	for (i=0;i<100;i+=4){
			printf("%i - %02X%02X%02X%02X - %c%c%c%c\n",i,(unsigned char) a[i+3],(unsigned char) a[i+2], (unsigned char) a[i+1], (unsigned char) a[i], a[i+3],a[i+2],a[i+1],a[i]);
	}

	close(file);
}











