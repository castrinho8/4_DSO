/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa que modifica el fichero "stack.txt"

Nota:
Los datos que aparecen acerda de posicioes de memoria y direcciones
del stack pueden variar en función del ordenador en donde sea ejecutado
el programa.

*/
#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(){
	int file;
	int dir_salto; //Direccion a saltar en hexadecimal 08048554
	int pos_ret; //Posición de la dirección de retorno en el stack 48
	int pos_arg; //Posicion donde se encuentra el argumento de "anotherfunction" 0xbffff334

	printf("MODIFICANDO FICHERO STACK.TXT:\n");

	printf("Que posicion modificar: SALTO:48\n");
	scanf("%i",&pos_ret);

	printf("Introduzca el valor de esa posicion: SALTO:08048554\n");
	scanf("%x",&dir_salto);

	if((file = open("stack.bin", O_WRONLY, 0777)) == -1){ 
		perror("No se pudo abrir el fichero.\n"); 
		return;
	}        

	lseek(file,pos_ret,SEEK_SET);

 	if(write(file, &dir_salto, sizeof(int)) == -1){//ESCRIBE SALTO
		perror("No se pudo escribir en fichero.\n"); 
		return; 
	}

	close(file);
}











