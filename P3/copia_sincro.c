/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Módulo que crea 2 threads que realizan doble buffering

*/
#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <aio.h>
#include <stdlib.h>

//Variables de control THREADS
int startt1 = 1; //Variable de control para el comienzo de t1
int ct = 0; //current thread
int tf[2]; //frame
int tr[2]; //return

//Variables de control de copiado
int f1_first,f1_r, f1_w,f2;
char buffer[1024];
int numbytes;

char mensaje[1024];

//Función que realentiza realizando cálculos inutiles	
void slow(){
	int i;
	long a;
	for(i=1;i<100000000;i++)
		a = 2000*4000/23;
}

//Función que cambia entre threads
void yield(){
	int a[10];
		
	tf[ct] = a[12];//frame de t1
	tr[ct] = a[13];//return de t1
	
	if(startt1){
		startt1 = 0;
		t1();
	}
	
	ct = !ct;

	a[12] = tf[ct];
	a[13] = tr[ct];
}

//Thread lectura
void t0(){
	volatile char a[10];
	volatile int i;

	//Bucle de lectura
	for(i=1;i<=5;i++){
		ct = 1;	
		//slow();
		sprintf(mensaje,"READ Iteración:%i-t1\n",i);
		write(1,mensaje,strlen(mensaje));

		numbytes = read(f1_r, &buffer, numbytes);
		write(f2, &buffer, numbytes);

		yield();
	}
}

//Thread escritura
void t1(){
	volatile char a[10];
	volatile int i;

	//Bucle de escritura
	for(i=1;i<=5;i++){
		ct = 0;
		//slow();
		sprintf(mensaje,"WRITE Iteración:%i-t0\n",i);
		write(1,mensaje,strlen(mensaje));

		if(write(f1_w,&buffer,numbytes) < 0)
	    	perror("Error escritura:");

		yield();
	}
}


int main(){

	//Abrir para crear el fichero si no existe
	f1_first = open("entrada.txt", O_WRONLY|O_CREAT|O_TRUNC, 0700);
	//Abrir para lectura
	f1_r = open("entrada.txt", O_RDONLY,0700);
	//Abrir para escritura con APPEND
	f1_w = open("entrada.txt", O_WRONLY|O_APPEND, 0700);
	//Fichero en el que realizar la lectura, en este caso salida standar
	f2 = 1;
	numbytes = strlen("VALOR\n");

	sprintf(mensaje,"\n-----Creación del fichero con el texto: 'VALOR\\n'-----\n");
	write(1,mensaje,strlen(mensaje));

	if(write(f1_first,"VALOR\n",numbytes) < 0)
    	perror("Error escritura:");

    close(f1_first);

    t0();

 	printf("\nFIN\n");

	/* Cierre de archivos */
	close(f1_r);
	close(f1_w);
	close(f2);
}

















