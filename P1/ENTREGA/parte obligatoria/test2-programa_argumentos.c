/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa para testear la posición y la evolucion de los argumentos de una función y que 
llama recursivamente a dicha funcion mostrando el stack en cada uno de los frames.

*/
#include <stdio.h>


int funcion1(int n,int arg1,int arg2){
	int i = 0;
	int a[10]; int b = 18; int bb = 19; int bbb = 20;

	printf("funcion1\n");

	for (i=0;i<10;i++){
		a[i] = 5;
	}

	if (n == 0){
		for (i=0;i<100;i++){
			printf("%d - \t%p %i\n",i,&(a[i]),a[i]);
		}
	}
	else funcion1(n-1,arg1,arg2);
	fflush(stdout);
}


int main(){
	printf("Inicio\n");
	funcion1(3,3,3);
	printf("Fin\n");
}
