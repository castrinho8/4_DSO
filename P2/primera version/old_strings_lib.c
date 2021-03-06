/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Modulo que contiene la implementación clásica de algunas funciones de "strings_lib"

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




char * insertado(int tam_dest,int tam_src,int pos_in, char * destino, char * origen){
	char * string = malloc((tam_dest+tam_src)*sizeof(char));
	strncpy(string,destino,pos_in);
	strncpy(string+pos_in,origen,tam_src);
	strncpy(string+pos_in+tam_src,destino+pos_in,tam_dest-pos_in+1);
	free(string);
}

char * borrado(int tam,char * str,int first,int last){
	char * temp = (char *) malloc(tam*sizeof(char));
	strncpy(temp,str,first);
	strcpy(temp+first,str+last);
	free(temp);
}

char * insertado_sobrescritura(int pos_in,char * destino, char * origen){
	
	//Obtiene el tamaño a borrar
	int tam_string_origen = strlen(origen);
	int tam_string_destino = strlen(destino);
	
	int last_overwrite = (pos_in+tam_string_origen)>(pos_in+tam_string_destino)? tam_string_destino:pos_in+tam_string_origen;
	
	//Para el caso de insertar una cadena que supera el final del string destino.
	if(last_overwrite > tam_string_destino) last_overwrite = tam_string_destino;

	char * salida = malloc(strlen(destino)+strlen(origen)*sizeof(char));
	salida = borrado(tam_string_destino,destino,pos_in,last_overwrite);
	salida = insertado(tam_string_destino,tam_string_origen,pos_in,destino,origen);
	free(salida);

}















