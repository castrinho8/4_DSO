/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa que llama recursivamente a una funcion, muestra el stack en cada uno de los frames
y realiza un salto temporal entre frames.

*/

#include <stdio.h>


int test = 0;

int funcion1(int n){
	int i = 0;
	int a[10]; int b = 18; int bb = 19; int bbb = 20; 

	printf("funcion1 - %i\n",n);

	for (i=0;i<10;i++){
		a[i] = 5;
	}

	if (n == 0){
		for (i=0;i<100;i++){
			printf("%d - \t%p %i\n",i,&(a[i]),a[i]);
		}
		//Modifica la direccion del frame anterior
		a[16]= a[16]+(4*24);
	}
	else funcion1(n-1);

	test++;
}


int main(){
	printf("Inicio\n");
	funcion1(3);
	printf("Valor sin salto: 4 Valor test: %i\n",test);
	printf("Fin\n");
}








