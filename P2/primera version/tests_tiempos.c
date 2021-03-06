/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa que realiza los test de duración sobre la librería implementada

*/
#include <math.h>
#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/uio.h>
#include <malloc.h>
#include <stdlib.h>


#include "strings_lib.c"
#include "tiempos_lib.c"

/*
Genera una cadena aleatoria del tamaño que le introducimos.
*/
char * random_str(int tam){

	int i;
	char * str = (char *) malloc (tam*sizeof(char));
	static const char text[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

   srand(time(0));
   for (i=0;i<tam;++i){
		str[i] = text[(rand() % (sizeof(text)-1))];
	}
  	str[i] = '\0';
   return str;
}
	

/*
INSERTADO
*/
void test_insertado_tiempos(int iter,int tam_str,int tam_max){

	//Definicion de variables
	int pos_in = 1;
	int tam_o = 1,tam_d= 1;
	struct iovec origen[tam_o];
	struct iovec destino[tam_d];
	
	int n_tests = (log(tam_max)-log(tam_str));
	double time_new[n_tests], time_classic[n_tests]; //Array para guardar tiempos
	int tam[n_tests]; //Array para guardar tamaños

	printf("Media\t\tTamaño string\t\tDuracion Media/Tamaño string\n");

	int i=0,j=0;
	for(i=tam_str;i<=tam_max;i*=2){
		
		//Creacion de strings aleatorios
		char * string1 = strdup(random_str(i));
		char * string = strdup(random_str(i));
		destino[0].iov_base = string1;
		destino[0].iov_len = strlen(string1);
		origen[0].iov_base = string;
		origen[0].iov_len = strlen(string);

		cadena * cadena_origen = crear_cadena(origen,tam_o);
		cadena * cadena_destino = crear_cadena(destino,tam_d);

		//Obtencion de tiempos
		time_new[j] = duracion_insertado(iter,pos_in,cadena_destino,cadena_origen);
		time_classic[j] = duracion_insertado_clasico(iter,pos_in,string1,string);
		//Obtencion del tamaño
		tam[j] = i;
		j++;
		
		//Liberacion de memoria
		free(string1);
		free(string);
		free(cadena_origen);
		free(cadena_destino);
	}
	
	imprime_tiempos(0,0,iter,time_new,n_tests,tam);
	imprime_tiempos(0,1,iter,time_classic,n_tests,tam);
}


/*
BORRADO
*/
void test_borrado_tiempos(int iter,int tam_str,int tam_max){	

	//Definicion de variables
	int first=1;int last=2;
	int tam_d= 1;
	struct iovec destino[tam_d];
	
	int n_tests = (log(tam_max)-log(tam_str));
	double time_new[n_tests], time_classic[n_tests]; //Array para guardar tiempos
	int tam[n_tests]; //Array para guardar tamaños

	printf("Media\t\tTamaño string\t\tDuracion Media/Tamaño string\n");

	int i=0,j=0;
	for(i=tam_str;i<=tam_max;i*=2){
		
		//Creacion de string aleatorio
		char * string1 = strdup(random_str(i));
		destino[0].iov_base = string1;
		destino[0].iov_len = strlen(string1);
		cadena * cadena_destino = crear_cadena(destino,tam_d);

		//Obtencion de tiempos
		time_new[j] = 	duracion_borrado(iter,cadena_destino,first,last);
		time_classic[j] = duracion_borrado_clasico(iter,string1,first,last);
		//Obtencion del tamaño
		tam[j] = i;
		j++;
		
		//Liberacion de memoria
		free(string1);
		free(cadena_destino);
	}
	
	imprime_tiempos(1,0,iter,time_new,n_tests,tam);
	imprime_tiempos(1,1,iter,time_classic,n_tests,tam);

}


/*
STR_DUP_V
*/
void test_str_dup_tiempos(int iter,int tam_str,int tam_max){

	//Definicion de variables
	int tam_d= 1;
	struct iovec destino[tam_d];
	
	int n_tests = (log(tam_max)-log(tam_str));
	double time_new[n_tests], time_classic[n_tests]; //Array para guardar tiempos
	int tam[n_tests]; //Array para guardar tamaños

	printf("Media\t\tTamaño string\t\tDuracion Media/Tamaño string\n");

	int i=0,j=0;
	for(i=tam_str;i<=tam_max;i*=2){
		
		//Creacion de string aleatorio
		char * string1 = strdup(random_str(i));
		destino[0].iov_base = string1;
		destino[0].iov_len = strlen(string1);
		cadena * cadena_destino = crear_cadena(destino,tam_d);

		//Obtencion de tiempos
		time_new[j] = 	duracion_str_dup(iter,cadena_destino);
		time_classic[j] = duracion_str_dup_clasico(iter,string1);
		//Obtencion del tamaño
		tam[j] = i;
		j++;
		
		//Liberacion de memoria
		free(string1);
		free(cadena_destino);
	}
	
	imprime_tiempos(2,0,iter,time_new,n_tests,tam);
	imprime_tiempos(2,1,iter,time_classic,n_tests,tam);
}


/*
CONCATENADO
*/
void test_concatenado_tiempos(int iter,int tam_str,int tam_max){

	//Definicion de variables
	int tam_o = 1,tam_d= 1;
	struct iovec origen[tam_o];
	struct iovec destino[tam_d];
	
	int n_tests = (log(tam_max)-log(tam_str));
	double time_new[n_tests], time_classic[n_tests]; //Array para guardar tiempos
	int tam[n_tests]; //Array para guardar tamaños

	printf("Media\t\tTamaño string\t\tDuracion Media/Tamaño string\n");

	int i=0,j=0;
	for(i=tam_str;i<=tam_max;i*=2){
		
		//Creacion de strings aleatorios
		char * string1 = strdup(random_str(i));
		char * string = strdup(random_str(i));
		destino[0].iov_base = string1;
		destino[0].iov_len = strlen(string1);
		origen[0].iov_base = string;
		origen[0].iov_len = strlen(string);

		cadena * cadena_origen = crear_cadena(origen,tam_o);
		cadena * cadena_destino = crear_cadena(destino,tam_d);

		//Obtencion de tiempos
		time_new[j] = duracion_concatenacion(iter,cadena_destino,cadena_origen);
		time_classic[j] = duracion_concatenacion_clasica(iter,string1,string);
		//Obtencion del tamaño
		tam[j] = i;
		j++;
		
		//Liberacion de memoria
		free(string1);
		free(string);
		free(cadena_origen);
		free(cadena_destino);
	}
	
	imprime_tiempos(3,0,iter,time_new,n_tests,tam);
	imprime_tiempos(3,1,iter,time_classic,n_tests,tam);
}


/*
COMPARACION
*/
void test_comparacion_tiempos(int iter,int tam_str,int tam_max){

	int tam_o = 1,tam_d= 1;
	struct iovec origen[tam_o];
	struct iovec destino[tam_d];
	
	int n_tests = (log(tam_max)-log(tam_str));

	double time_new[n_tests], time_classic[n_tests];
	int tam[n_tests];

	int i=0,j=0;
	printf("Media\t\tTamaño string\t\tDuracion Media/Tamaño string\n");

	for(i=tam_str;i<=tam_max;i*=2){
		char * string1 = strdup(random_str(i));
		char * string = strdup(random_str(i));

		destino[0].iov_base = string1;
		destino[0].iov_len = strlen(string1);
		origen[0].iov_base = string;
		origen[0].iov_len = strlen(string);

		cadena * cadena_origen = crear_cadena(origen,tam_o);
		cadena * cadena_destino = crear_cadena(destino,tam_d);

		time_new[j] = duracion_comparacion(iter,cadena_destino,cadena_origen);
		time_classic[j] = duracion_comparacion_clasica(iter,string1,string);
		tam[j] = i;
		j++;

		free(string1);
		free(string);
		free(cadena_origen);
		free(cadena_destino);
	}
	imprime_tiempos(4,0,iter,time_new,n_tests,tam);
	imprime_tiempos(4,1,iter,time_classic,n_tests,tam);
}

/*
INSERTADO CON SOBREESCRITURA
*/
void test_insert_over_tiempos(int iter,int tam_str,int tam_max){

	//Definicion de variables
	int pos_in = 1;
	int tam_o = 1,tam_d= 1;
	struct iovec origen[tam_o];
	struct iovec destino[tam_d];
	
	int n_tests = (log(tam_max)-log(tam_str));
	double time_new[n_tests], time_classic[n_tests]; //Array para guardar tiempos
	int tam[n_tests]; //Array para guardar tamaños

	printf("Media\t\tTamaño string\t\tDuracion Media/Tamaño string\n");

	int i=0,j=0;
	for(i=tam_str;i<=tam_max;i*=2){
		
		//Creacion de strings aleatorios
		char * string1 = strdup(random_str(i));
		char * string = strdup(random_str(i));
		destino[0].iov_base = string1;
		destino[0].iov_len = strlen(string1);
		origen[0].iov_base = string;
		origen[0].iov_len = strlen(string);

		cadena * cadena_origen = crear_cadena(origen,tam_o);
		cadena * cadena_destino = crear_cadena(destino,tam_d);

		//Obtencion de tiempos
		time_new[j] = duracion_insert_over(iter,pos_in,cadena_destino,cadena_origen);
		time_classic[j] = duracion_insert_over_clasica(iter,pos_in,string1,string);
		//Obtencion del tamaño
		tam[j] = i;
		j++;
		
		//Liberacion de memoria
		free(string1);
		free(string);
		free(cadena_origen);
		free(cadena_destino);
	}
	
	imprime_tiempos(5,0,iter,time_new,n_tests,tam);
	imprime_tiempos(5,1,iter,time_classic,n_tests,tam);
}


int main(){

	char control[1];
	int iter = 100;
	int tam_str = 2048;
	int tam_max = 1024*1024;

	printf("Introduzca el número de iteraciones.\n");
	scanf("%i",&iter);
	scanf("%c",control);
/*
	printf("\n\n\n\n--COMPARACION--\n\n");
	test_comparacion_tiempos(iter,tam_str,tam_max);
	scanf("%c",control);
	printf("\n\n\n\n--INSERTADO--\n\n");
	test_insertado_tiempos(iter,tam_str,tam_max);
	scanf("%c",control);

	printf("\n\n\n\n--BORRADO--\n\n");
	test_borrado_tiempos(iter,tam_str,tam_max);
	scanf("%c",control);

	printf("\n\n\n\n--COPIA--\n\n");
	test_str_dup_tiempos(iter,tam_str,tam_max);
	scanf("%c",control);

	printf("\n\n\n\n--CONCATENADO--\n\n");
	test_concatenado_tiempos(iter,tam_str,tam_max);
	scanf("%c",control);
*/
	printf("\n\n\n\n--INSERTADO CON SOBREESCRITURA--\n\n");
	test_insert_over_tiempos(iter,tam_str,tam_max);


}










