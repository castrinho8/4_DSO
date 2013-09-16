#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/uio.h>


//Programa para comprobar si la inserccion de un array en otro, en las mismas condiciones, la funcion tarda el mismo tiempo o no

int duracion_insertado(int iter, struct iovec * src, int nodos_src, struct iovec * dest, int nodos_dest, int pos_in){

	struct timeval t_ini, t_fin;
	int i,tam=0;
	double time=0;

	gettimeofday(&t_ini, NULL);
	for(i=0;i<iter;i++)
		str_insert_v(src,nodos_src,dest,nodos_dest,pos_in);
	gettimeofday(&t_fin, NULL);    

	time = diff_time(&t_ini,&t_fin);
	tam = tam_str_v(src,nodos_src);

	imprime_tiempos(0,iter,time,tam);
}

int main(){

	char *str0 = "hello ";
	char *str1 = "world\n";

	int tam_iov = 2, tam_lec = 1; 
	struct iovec iov[tam_iov];
	struct iovec lec[tam_lec];
	struct iovec * salida;

	iov[0].iov_base = str0;
	iov[0].iov_len = strlen(str0);
	iov[1].iov_base = str1;
	iov[1].iov_len = strlen(str1);
	lec[0].iov_base = str2;
	lec[0].iov_len = strlen(str2);


	duracion_insertado(int iter, struct iovec * src, int nodos_src, struct iovec * dest, int nodos_dest, int pos_in)
	
}
