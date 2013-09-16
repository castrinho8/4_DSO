/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Módulo que contiene la implementacion del tipo "cadena" y las funciones para su uso.

*/
#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/uio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct cadena_ cadena;

struct cadena_{
    int  tam; //Número de nodos
    struct iovec *nodo; //Puntero al array de estructuras
};


/*-----FUNCIONES LIBRERIA------*/

/*Crea una nueva cadena a partir de un array de structs iovec.*/
cadena * crear_cadena(struct iovec * nodo, int tamanho){
	cadena * new_cadena;

	if ((new_cadena = (cadena *) malloc(sizeof(cadena))) == NULL)
		return NULL;

	new_cadena->tam = tamanho;
	new_cadena->nodo = nodo;
	return new_cadena;
}

/*Modifica una cadena a partir de otra*/
cadena * modificar_cadena(cadena * cad,struct iovec *nodo,int tamanho){
	cad->nodo = nodo;
	cad->tam = tamanho;
	return cad;
}

/*Comprueba si ha habido un error.*/
int test_error(cadena * cad){
		return ((cad->nodo == NULL) && (cad->tam == -1));
}

/*Imprime una cadena.*/
void print_cadena(struct iovec * iov,int tam_array){

	int i;
	for(i=0;i<tam_array;i++){
		write(STDOUT_FILENO,iov[i].iov_base,(iov[i].iov_len)*sizeof(char));
	}
}






















