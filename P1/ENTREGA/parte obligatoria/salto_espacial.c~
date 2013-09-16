/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa que llama recursivamente a una funcion, muestra el stack en cada uno de los frames
y finalmente se salta una instruccion al modificar el valor de retorno de una función.

*/

#include <stdio.h>
#define DIST_SALTO 5


int funcion1(int n){
	int i = 0;
	int a[10]; int b = 18; int bb = 19; int bbb = 20; 

	printf("funcion1\n");

	for (i=0;i<10;i++){
		a[i] = 5;
	}

	//Modifica la direccion de retorno segun el resultado de la función distancia_salto
	a[89]= a[89]+DIST_SALTO;;

	if (n == 0){
		for (i=0;i<100;i++){
			printf("%d - \t%p %i\n",i,&(a[i]),a[i]);
		}
	}
	else funcion1(n-1);
	fflush(stdout);
}


int main(){
	int x = 0;	
	printf("Inicio\n");
	funcion1(3);

	/*Al haber cambiado la direccion de retorno se salta el x++, y no suma "1" a "x" y lo imprime*/
	x++;
	printf("x = %d\n",x);
	printf("Fin\n");
}







