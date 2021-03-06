/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa que crea 3 hilos y realiza el factorial de un número introducido.

*/
#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <aio.h>


//Array de control para las primeras llamadas a los threads
int start[3];

//Array de control para los threads terminados
int fin[3];

//Variables para guardar los números para los diferentes threads
int numero_t0 = 5;
int numero_t1 = 6;
int numero_t2 = 7;
//8192

//Variables para guardar los factoriales para los diferentes threads
int fact_t0 = 1;
int fact_t1 = 1;
int fact_t2 = 1;

int ct = 0; //Current Thread
int t_frame[4]; //Almacena las direcciones de los frames
int t_return[4]; //Almacena las direcciones de retorno

//Variable para imprimir textos
char mensaje[1024];

//Función que cambia entre threads
void yield(){
	int a[10];
	int i = 0;
	//Guarda las direcciones
	t_frame[ct] = a[13];//frame
	t_return[ct] = a[14];//return

	//1º ACCESO A T0
	if(start[0]){
		start[0]= 0;
		fact_t0 = t0(numero_t0);
		fin[0] = 1;
	}else{
		//1º ACCESO A T1
		if(start[1]){
			start[1] = 0;
			fact_t1 = t1(numero_t1);
			fin[1] = 1;
		}else{
			//1º ACCESO A T2
			if(start[2]){
				start[2] = 0;
				fact_t2 = t2(numero_t2);
				fin[2] = 1;
			}
		}
	}

	//Cambia el thread actual
	for(i=0;i<=2;i++){
		ct = (ct+1) % 3;

		if(!fin[ct])
			break;
	}

	//Si es el final se carga el frame de la funcion "frame"
	if((fin[0]) && (fin[1]) && (fin[2]))
		ct = 3;

	a[13] = t_frame[ct];
	a[14] = t_return[ct];
}

//Función que coloca el SP en el lugar adecuado
void adjust_frame(){
	yield();
	return;
}

int t0(int numero_t0){
	int a[10];
	int temp = 1;
	if (numero_t0){

		temp = t0(numero_t0-1);
		
		//printf("Thread-0\n");

		//sprintf(mensaje,"Thread-0\n");
		//write(1,mensaje,strlen(mensaje));

		adjust_frame();
		return numero_t0 * temp;
	}else{
		ct=0;
		adjust_frame();
		return 1;
	}
}


int t1(int numero_t1){
	int a[10];
	int temp = 1;
	if (numero_t1){

		temp = t1(numero_t1-1);
		//printf("Thread-1\n");
		//sprintf(mensaje,"Thread-1\n");
		//write(1,mensaje,strlen(mensaje));

		adjust_frame();
		return numero_t1 * temp;
	}else{
		ct=1;
		adjust_frame();
		return 1;
	}
}

int t2(int numero_t2){
	int a[10];
	int temp = 1;
	if (numero_t2){

		temp = t2(numero_t2-1);
		//printf("Thread-2\n");
		//sprintf(mensaje,"Thread-2\n");
		//write(1,mensaje,strlen(mensaje));

		adjust_frame();
		return numero_t2 * temp;
	}else{
		ct=2;
		adjust_frame();
		return 1;
	}
}


int main(int argc, char *argv[]){
	int i;
	//Inicialización de variables
	for(i=0;i<=2;i++){
		fin[i] = 0;
		start[i] = 1;
	}

	ct=3;
	adjust_frame();

	int salidat0 = fact_t0;
	int salidat1 = fact_t1;
	int salidat2 = fact_t2;

	printf("Thread 0 - Resultado:%i\nThread 1 - Resultado:%i\nThread 2 - Resultado:%i\n",salidat0,salidat1,salidat2);
}

















