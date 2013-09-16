//cola.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef MAX_ITEMS
	#define MAX_ITEMS 100
#endif


typedef struct {
	char items[MAX_ITEMS];
	int maxNum;
	int num;
	int ppio;
	int final;
} tCola;


int cola_vacia (tCola *c);
void crear_cola (tCola * c, int tamanhomax);
void insertar (char x, tCola * c);
char primero (tCola *c);
char eliminar_primero (tCola *c);
void mostrarCola(tCola *c);









