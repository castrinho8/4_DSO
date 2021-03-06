/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Módulo que contiene las funciones para realizar la medición de tiempos.

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

#include "old_strings_lib.c"


int timedef = 0;

/*
Funcion que calcula el tiempo.
*/
int get_time(){

	int ret;
	struct timeval t;
	gettimeofday(&t,NULL);

	if(timedef){
		ret = t.tv_usec - timedef;
		timedef = 0;
		return ret;
	}else{
		timedef = t.tv_usec;
		return 0;
	}
}

/*
* IMPRIME TIEMPOS
*/
void imprime_tiempos(int type,int clasic,int iter,double *time,int tam_time,int *tam){

	int i;
	switch(type){
		case 0:(clasic)?printf("INSERTADO CLASICO\n"):printf("INSERTADO\n");break;
		case 1:(clasic)?printf("BORRADO CLASICO\n"):printf("BORRADO\n");break;
		case 2:(clasic)?printf("COPIA CLASICA\n"):printf("COPIA\n");break;
		case 3:(clasic)?printf("CONCATENADO CLASICO\n"):printf("CONCATENADO\n");break;
		case 4:(clasic)?printf("COMPARACION CLASICA\n"):printf("COMPARACION\n");break;
		case 5:(clasic)?printf("INSERTADO CON SOBREESCRITURA CLASICA\n"):printf("INSERTADO CON SOBREESCRITURA\n");break;
	}

	for(i=0;i<=tam_time;i++)
		printf("%fus\t%i\t\t\t%f\n",time[i]/iter,tam[i],(time[i]/iter)/tam[i]);
}



/*
* INSERTADO
*/
double duracion_insertado(int iter,int pos_in,cadena * cad_destino,cadena * cad_origen){

	struct timeval t_ini, t_fin;
	int i,tam=0;
	double time=0;

	//Medición de tiempos str_insert_v 
	for(i=0;i<iter;i++){
		get_time();
		str_insert_v(pos_in,cad_destino,cad_origen);
		time += get_time();
	}

	return time;
}


double duracion_insertado_clasico(int iter,int pos_in,char * destino,char * origen){

	int i,j,tam=0;
	int time=0;
	int tam_dest = strlen(destino), tam_src = strlen(origen);

	//Medición de tiempos insertado clasico
	for(i=0;i<iter;i++){
		char * string = malloc((tam_dest+tam_src)*sizeof(char));

		get_time();
		strncpy(string,destino,pos_in);
		strncpy(string+pos_in,origen,tam_src);
		strncpy(string+pos_in+tam_src,destino+pos_in,tam_dest-pos_in+1);
		time += get_time();

		free(string);
	}

	return time;
}

/*
* BORRADO
*/
double duracion_borrado(int iter,cadena * cad_str,int first, int last){
	
	int i;
	double time=0;

	for(i=0;i<iter;i++){
		get_time();
		str_delete_v(cad_str,first,last);
		time += get_time();
	}
	return time;
}


double duracion_borrado_clasico(int iter,char * str,int first,int last){

	int i;
	double time=0;
	int tam_str = strlen(str);

	for(i=0;i<iter;i++){
		char * temp = (char *) malloc(tam_str*sizeof(char));

		get_time();
		strncpy(temp,str,first);
		strcpy(temp+first,str+last);
		time += get_time();

		free(temp);
	}

	return time;
}


/*
* STR_DUP
*/
double duracion_str_dup(int iter,cadena * cad_origen){

	int i;
	double time=0;

	for(i=0;i<iter;i++){
		time += get_time();
		str_dup_v(cad_origen);
		time += get_time();
	}
	return time;
}


double duracion_str_dup_clasico(int iter,char * origen){

	int i;
	double time=0;
	int tam_src = strlen(origen);

	for(i=0;i<iter;i++){
		char * temp = (char *) malloc(tam_src*sizeof(char));

		get_time();
		temp = strdup(origen);
		time += get_time();

		free(temp);
	}
	return time;
}


/*
* CONCATENADO
*/
double duracion_concatenacion(int iter,cadena * cad_destino, cadena * cad_origen){

	int i,tam=0;
	double time=0;

	for(i=0;i<iter;i++){
		get_time();
		str_cat_v(cad_destino,cad_origen);
		time += get_time();
	}
	return time;
}

double duracion_concatenacion_clasica(int iter,char * destino,char * origen){

	int i;
	double time=0;
	int tam = strlen(origen)+strlen(destino);

	for(i=0;i<iter;i++){
		char * temp = (char *) malloc (strlen(destino)+strlen(origen)*sizeof(char));

		get_time();
		temp = strcpy(temp,destino);
		strcat(temp,origen);
		time += get_time();

		free(temp);
	}
	return time;
}

/*
* COMPARACION
*/
double duracion_comparacion(int iter,cadena * cad_destino,cadena * cad_origen){

	int i,tam=0;
	double time=0;

	for(i=0;i<iter;i++){
		get_time();
		str_cmp_v(cad_destino,cad_origen);
		time += get_time();
	}
	return time;
}

double duracion_comparacion_clasica(int iter,char * destino,char * origen){

	int i;
	double time=0;

	for(i=0;i<iter;i++){
		get_time();
		strcmp(destino,origen);
		time += get_time();
	}
	return time;
}

/*
* INSERTADO CON SOBRESCRITURA
*/
double duracion_insert_over(int iter,int pos_in,cadena * cad_destino,cadena * cad_origen){

	int i;
	double time=0;

	for(i=0;i<iter;i++){
		get_time();
		insert_over(pos_in,cad_destino,cad_origen);
		time += get_time();
	}
	return time;
}


double duracion_insert_over_clasica(int iter,int pos_in,char * destino,char * origen){

	int i;
	double time=0;

	for(i=0;i<iter;i++){
		get_time();
		insertado_sobrescritura(pos_in,destino,origen);
		time += get_time();
	}
	return time;
}









