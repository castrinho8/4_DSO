/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Módulo que contiene la implementación de las funciones de tratamiento de strings.

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

#include "cadena_lib.c"


//Cabeceras de las funciones implementadas.
cadena * str_insert_v(int pos_in,cadena * cad_destino,cadena * cad_origen);
cadena * str_delete_v(cadena * cad_str, int first, int last);
cadena * str_dup_v(cadena * cad_origen);
cadena * str_cat_v(cadena * cad_destino, cadena * cad_origen);
int str_cmp_v(cadena * cad_a,cadena * cad_b);
void str_printf_v(cadena * cad_str);

//Funcion optativa
cadena * insert_over(int pos_in, cadena * cad_destino,cadena * cad_origen);


/*----------FUNCIONES EXTRA-----------*/

/*
* TAM_STR_V: Funcion que recorre el string y devuelve el tamaño total de caracteres.
* SALIDA: -1=Error; Other=tamaño del string
*/
int tam_str_v(cadena * cad_palabra){

	struct iovec * str = cad_palabra->nodo;
	int tam_str = cad_palabra->tam;
	int i=0,ii=0;
	int tam = 0;

	if(tam_str < 0){
		printf("\nERROR in 'tam_str_v': El tamaño introducido no es válido.\n");
		return -1;
	}

	while(i<tam_str){
		if(ii == str[i].iov_len){ 
			i++;
			ii=0;
			continue;
		}
		ii++;
		tam++;
	}
	return tam;
}


/*
* SEEK: Devuelve las posiciones en array y relativa.
* SALIDA: 0=Terminacion normal; -1=Error;
*/
int seek_pos(int pos, cadena * cad_palabra, int *pos_array, int *pos_rel){

	struct iovec * array = cad_palabra->nodo;
	int tam_array = cad_palabra->tam;
	
	int count = 0, pos_array_loc = 0;

	if(pos < 0){
		printf("\nERROR in 'seek_pos': Posición negativa.\n");
		return -1;
	}
	
	if(pos == 0){
		*pos_array = 0;
		*pos_rel = 0;
		return 0;
	}

	while(count < pos){
		
		//Comprobamos que la posición indicada esta dentro del array
		if (pos_array_loc > tam_array){ 
			return -2;
		}
		count = count + array[pos_array_loc].iov_len;
		pos_array_loc++;
	}

	*pos_array = pos_array_loc - 1; //ENCUENTRA LA POSICION EN EL ARRAY DE ESTRUCTURAS
	*pos_rel = pos - (count - array[*pos_array].iov_len); //ENCUENTRA POSICION RELATIVA (Dentro del array)
	return 0;
}


/*----------FUNCIONES LIBRERIA---------*/

/* 
*  a)- STR_INSERT_V: Inserta el string "origen" en "destino" en la posicion indicada SIN SOBREESCRIBIR
*	SALIDA:  crear_cadena(NULL,-1)=Error; Other=Puntero a la nueva "cadena";
*/
cadena * str_insert_v(int pos_in,cadena * cad_destino,cadena * cad_origen){

	//Inicializa las estructuras iovec
	struct iovec * src = cad_origen->nodo;
	int nodos_src = cad_origen->tam;
	struct iovec * dest = cad_destino->nodo;
	int nodos_dest = cad_destino->tam;

	int pos_nodo = 0,pos_rel = 0;
	int err;

	//Busca y comprueba errores.
	if((err = seek_pos(pos_in,cad_destino,&pos_nodo,&pos_rel)) < 0){
		if(err==-2)
			printf("\nERROR: La posición introducida es mayor al tamaño del string.\n");
		return modificar_cadena(cad_destino,NULL,-1);
	}

	struct iovec * new_node = (struct iovec *) malloc(sizeof(struct iovec));

	int tam_nodos = 0;

	//1: Hay estructuras antes de "pos_nodo"
	if(pos_nodo!=0){
		tam_nodos = pos_nodo;
		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_destino,NULL,-1);

		//copiar estructuras anteriores
		memcpy(new_node,dest,(tam_nodos)*sizeof(struct iovec));
	}

	//2: Hay cosas antes de "pos_rel"
	if(pos_rel!=0){
		tam_nodos++;
		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_destino,NULL,-1);

		//Copia estructura "pos_nodo" hasta "pos_rel"
		memcpy(new_node+(tam_nodos-1),dest+pos_nodo,sizeof(struct iovec));//copia nodo
		new_node[tam_nodos-1].iov_len = pos_rel; //cambiamos el tamaño
	}

	//3: Copiar nodo "ORIGEN"
	int pos_insercion = tam_nodos;
	tam_nodos = tam_nodos + nodos_src;

	if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
		return modificar_cadena(cad_destino,NULL,-1);

	//Copia el nodo
	memcpy(new_node+pos_insercion,src,(nodos_src)*sizeof(struct iovec));

	//4: Hay cosas despues de "pos_rel"
	if(pos_rel!=dest[pos_nodo].iov_len){
		tam_nodos++;
		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_destino,NULL,-1);

		//Copia estructura "pos_nodo" desde "pos_rel"
		memcpy(new_node+(tam_nodos-1),dest+pos_nodo,sizeof(struct iovec));//copia nodo
		new_node[tam_nodos-1].iov_base = new_node[tam_nodos-1].iov_base + pos_rel; //cambiamos el puntero
		new_node[tam_nodos-1].iov_len = new_node[tam_nodos-1].iov_len - pos_rel; //cambiamos el tamaño
	}

	//5: Hay estructuras despues de "pos_nodo"
	if(pos_nodo!=nodos_dest){
		int pos_insercion = tam_nodos;
		tam_nodos = tam_nodos + (nodos_dest-(pos_nodo+1));

		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_destino,NULL,-1);

		//copiar estructuras posteriores
		memcpy(new_node+pos_insercion,dest+pos_nodo+1,(nodos_dest-(pos_nodo+1))*sizeof(struct iovec));
		return modificar_cadena(cad_destino,new_node,tam_nodos);
	}
	return modificar_cadena(cad_destino,new_node,tam_nodos-1);
}


/*
*	b)- STR_DELETE_V: Borrar un rango de caracteres de un string
*	SALIDA: crear_cadena(NULL,-1)=Error; Other=Puntero a la nueva "cadena"
*/
cadena * str_delete_v(cadena * cad_str, int first, int last){

	//Inicializa las estructuras iovec
	struct iovec * str = cad_str->nodo;
	int nodos_str = cad_str->tam;

	int nodo_first = 0,rel_first = 0;
	int nodo_last = 0, rel_last = 0;
	struct iovec * new_node = (struct iovec *) malloc(sizeof(struct iovec));

	int err = 0;
	if(first > last){
		printf("\nERROR in 'str_delete_v': Las posiciones a borrar son incorrectas.\n");
		return modificar_cadena(cad_str,NULL,-1);
	}

	//Busca first y comprueba errores.
	if((err = seek_pos(first,cad_str,&nodo_first,&rel_first)) < 0){
		if(err==-2)
			printf("\nERROR: La posición indicada es mayor al tamaño del string.\n");
		return modificar_cadena(cad_str,NULL,-1);
	}
	//Busca last y comprueba errores.
	if((err = seek_pos(last,cad_str,&nodo_last,&rel_last)) < 0){
		if(err==-2)
			printf("\nERROR: La posición indicada es mayor al tamaño del string.\n");
		return modificar_cadena(cad_str,NULL,-1);
	}

	int tam_nodos = 0;

	//1: Hay estructuras antes de "nodo_first"
	if(nodo_first!=0){
		tam_nodos = nodo_first;
		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_str,NULL,-1);

		//copiar estructuras anteriores
		memcpy(new_node,str,(tam_nodos)*sizeof(struct iovec));
	}

	//2: Hay cosas antes de "rel_first"
	if(rel_first!=0){
		tam_nodos++;
		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_str,NULL,-1);

		//Copia estructura "nodo_first" hasta "rel_first"
		memcpy(new_node+(tam_nodos-1),str+nodo_first,sizeof(struct iovec));//copia nodo
		new_node[tam_nodos-1].iov_len = rel_first; //cambiamos el tamaño
	}

	//3: Hay cosas despues de "rel_last"
	if(rel_last!=str[nodo_last].iov_len){
		tam_nodos++;
		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_str,NULL,-1);

		//Copia estructura "nodo_last" desde "rel_last"
		memcpy(new_node+(tam_nodos-1),str+nodo_last,sizeof(struct iovec));//copia nodo
		new_node[tam_nodos-1].iov_base = new_node[tam_nodos-1].iov_base + rel_last; //cambiamos el puntero
		new_node[tam_nodos-1].iov_len = new_node[tam_nodos-1].iov_len - rel_last; //cambiamos el tamaño
	}

	//4: Hay estructuras despues de "nodo_last"
	if(nodo_last!=nodos_str){
		int pos_insercion = tam_nodos;
		tam_nodos = tam_nodos + (nodos_str-(nodo_last));

		if((new_node = (struct iovec *) realloc(new_node,(tam_nodos)*sizeof(struct iovec))) == NULL)
			return modificar_cadena(cad_str,NULL,-1);

		//copiar estructuras posteriores
		memcpy(new_node+pos_insercion,str+nodo_last+1,(nodos_str-(nodo_last+1))*sizeof(struct iovec));
	}
	return modificar_cadena(cad_str,new_node,tam_nodos-1);
}

/*
* c)- STR_DUP_V: Copia la cadena en otra variable y devuelve la copia.
*/
cadena * str_dup_v(cadena * cad_origen){

	//Inicializa las estructuras iovec
	struct iovec * src = cad_origen->nodo;
	int nodos_src = cad_origen->tam;
	
	struct iovec * new_node = (struct iovec *) malloc(nodos_src * sizeof(struct iovec));

	memcpy(new_node,src,nodos_src*sizeof(struct iovec));
	
	return crear_cadena(new_node,nodos_src);
}


/*
* d)- STR_CAT_V: Concatenar dos strings existentes.
* SALIDA: crear_cadena(NULL,-1)=Error; Other=Puntero a la nueva "cadena";
*/
cadena * str_cat_v(cadena * cad_destino, cadena * cad_origen){
	
	//Inicializa las estructuras iovec
	struct iovec * a = cad_destino->nodo;
	int nodos_a = cad_destino->tam;
	struct iovec * b = cad_origen->nodo;
	int nodos_b = cad_origen->tam;

	struct iovec * new_node;

	if ((new_node = (struct iovec *) malloc((nodos_b + nodos_a)*sizeof(struct iovec))) == NULL)
		return modificar_cadena(cad_destino,NULL,-1);

	//Copiar "destino"
	memcpy(new_node,a,(nodos_a*sizeof(struct iovec)));
	//Copiar "origen"
	memcpy(new_node+nodos_a,b,(nodos_b*sizeof(struct iovec)));

	return modificar_cadena(cad_destino,new_node,nodos_a+nodos_b);
}


/*
*	e)- STR_CMP_V: Comparar dos strings existentes.
*	SALIDA: 0=False; 1=True; -1=Error;
*/
int str_cmp_v(cadena * cad_a,cadena * cad_b){

	//Inicializa las estructuras iovec
	struct iovec * a = cad_a->nodo;
	int nodos_a = cad_a->tam;
	struct iovec * b = cad_b->nodo;
	int nodos_b = cad_b->tam;

	int i=0,ii=0,j=0,jj=0;

	if((nodos_a < 0)|| (nodos_b < 0)){
		printf("\nERROR in 'str_cmp_v': El tamaño de uno de las estructuras no es adecuado.\n");
		return -1;
	}

	int min, res;
	while((i<nodos_a) && (j<nodos_b)){

		min = (a[i].iov_len-ii < b[j].iov_len-jj)? a[i].iov_len-ii:b[j].iov_len-jj;

		if(res = memcmp(a[i].iov_base+ii,b[j].iov_base+jj,min))
			return 0;

		if(a[i].iov_len-ii < b[j].iov_len-jj){
			jj = min;
			ii=0;
			i++;
		}else
			if(a[i].iov_len > b[j].iov_len){
				ii = min;
				jj=0;
				j++;
			}else{
				i++;
				j++;
				ii = 0;
				jj = 0;
			}
	}
	return((i==nodos_a) && (ii==0) && (j==nodos_b) && (jj==0));
}


/*
* f)- STR_PRINTF_V: Función que imprime una "cadena"
*/
void str_printf_v(cadena * cad_str){

	//Inicializa las estructuras iovec
	struct iovec * iov = cad_str->nodo;
	int tam_array = cad_str->tam;

	print_cadena(iov,tam_array);
}



/*	
*	OPT: INSERT_OVER: Realizar una copia de un string existente en otro en la posicion indicada
*	SALIDA: crear_cadena(NULL,-1)=Error; Other=Puntero a la "cadena" destino;
*/
cadena * insert_over(int pos_in, cadena * cad_destino,cadena * cad_origen){

	//Inicializa las estructuras iovec
	struct iovec * src = cad_origen->nodo;
	int nodos_src = cad_origen->tam;
	struct iovec * dest = cad_destino->nodo;
	int nodos_dest = cad_destino->tam;

	int pos_nodo = 0,pos_rel = 0;
	//Busca y comprueba errores.
	if(seek_pos(pos_in,cad_destino,&pos_nodo,&pos_rel) < 0)
		return modificar_cadena(cad_destino,NULL,-1);
	
	//Obtiene el tamaño a borrar
	int tam_string_origen = tam_str_v(cad_origen);
	int tam_string_destino = tam_str_v(cad_destino);
	
	int last_overwrite = pos_in+tam_string_origen;

	//Para el caso de insertar una cadena que supera el final del string destino.
	if(last_overwrite > tam_string_destino) last_overwrite = tam_string_destino;

	//Borrar para hacer sitio.
	cad_destino = str_delete_v(cad_destino,pos_in,last_overwrite);

	if (test_error(cad_destino))
		return modificar_cadena(cad_destino,NULL,-1);

	//Insertar en la posicion.
	cad_destino = str_insert_v(pos_in,cad_destino,cad_origen);
	if (test_error(cad_destino))
		return modificar_cadena(cad_destino,NULL,-1);

	return cad_destino;
}



















