/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Programa que realiza los test de funcionamiento sobre la librería implementada

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

#include "strings_lib.c"

/*
COMPARACION
*/
void test_comparacion(){

	//Tamaño nodo igual, string igual
	int tam_p1_a = 2, tam_p1_b = 2; 
	struct iovec p1_a[tam_p1_a];
	struct iovec p1_b[tam_p1_b];

	p1_a[0].iov_base = "hello ";
	p1_a[0].iov_len = strlen("hello ");
	p1_a[1].iov_base = "world\n";
	p1_a[1].iov_len = strlen("world\n");

	p1_b[0].iov_base = "hello ";
	p1_b[0].iov_len = strlen("hello ");
	p1_b[1].iov_base = "world\n";
	p1_b[1].iov_len = strlen("world\n");

	cadena * cadena_p1_a = crear_cadena(p1_a,tam_p1_a);
	cadena * cadena_p1_b = crear_cadena(p1_b,tam_p1_b);

	int test1;
	printf("1- Tamaño nodo igual, string igual:\n");
	if((test1 = str_cmp_v(cadena_p1_a,cadena_p1_b)) == -1)
		exit(0);

	str_printf_v(cadena_p1_a);
	printf("%i ---\n",test1);
	str_printf_v(cadena_p1_b);
	printf("-\n\n");

	//Tamaño nodo distinto, string igual
	int tam_p2_a = 3, tam_p2_b = 2; 
	struct iovec p2_a[tam_p2_a];
	struct iovec p2_b[tam_p2_b];

	p2_a[0].iov_base = "hello ";
	p2_a[0].iov_len = strlen("hello ");
	p2_a[1].iov_base = "wor";
	p2_a[1].iov_len = strlen("wor");
	p2_a[2].iov_base = "ld\n";
	p2_a[2].iov_len = strlen("ld\n");

	p2_b[0].iov_base = "hello ";
	p2_b[0].iov_len = strlen("hello ");
	p2_b[1].iov_base = "world\n";
	p2_b[1].iov_len = strlen("world\n");

	cadena * cadena_p2_a = crear_cadena(p2_a,tam_p2_a);
	cadena * cadena_p2_b = crear_cadena(p2_b,tam_p2_b);

	int test2;
	printf("2- Tamaño nodo distinto, string igual:\n");
	if((test2 = str_cmp_v(cadena_p2_a,cadena_p2_b)) == -1)
		exit(0);

	str_printf_v(cadena_p2_a);
	printf("%i ---\n",test2);
	str_printf_v(cadena_p2_b);
	printf("-\n\n");

	//Tamaño nodo igual, string distinto
	int tam_p3_a = 2, tam_p3_b = 2; 
	struct iovec p3_a[tam_p3_a];
	struct iovec p3_b[tam_p3_b];

	p3_a[0].iov_base = "hello ";
	p3_a[0].iov_len = strlen("hello ");
	p3_a[1].iov_base = "world";
	p3_a[1].iov_len = strlen("world");

	p3_b[0].iov_base = "hello ";
	p3_b[0].iov_len = strlen("hello ");
	p3_b[1].iov_base = "woald";
	p3_b[1].iov_len = strlen("woald");

	cadena * cadena_p3_a = crear_cadena(p3_a,tam_p3_a);
	cadena * cadena_p3_b = crear_cadena(p3_b,tam_p3_b);

	int test3;
	printf("3- Tamaño nodo igual, string distinto:\n");
	if((test3 = str_cmp_v(cadena_p3_a,cadena_p3_b)) == -1)
		exit(0);

	str_printf_v(cadena_p3_a);
	printf("\n%i ---\n",test3);
	str_printf_v(cadena_p3_b);
	printf("\n-\n\n");

	//Tamaño nodo distinto, string distinto
	int tam_p4_a = 3, tam_p4_b = 2; 
	struct iovec p4_a[tam_p4_a];
	struct iovec p4_b[tam_p4_b];

	p4_a[0].iov_base = "hello ";
	p4_a[0].iov_len = strlen("hello ");
	p4_a[1].iov_base = "wor ";
	p4_a[1].iov_len = strlen("wor ");
	p4_a[2].iov_base = "ld\n";
	p4_a[2].iov_len = strlen("ld\n");

	p4_b[0].iov_base = "hello ";
	p4_b[0].iov_len = strlen("hello ");
	p4_b[1].iov_base = "world\n";
	p4_b[1].iov_len = strlen("world\n");

	cadena * cadena_p4_a = crear_cadena(p4_a,tam_p4_a);
	cadena * cadena_p4_b = crear_cadena(p4_b,tam_p4_b);

	int test4;
	printf("4- Tamaño nodo distinto, string distinto:\n");
	if((test4 = str_cmp_v(cadena_p4_a,cadena_p4_b)) == -1)
		exit(0);

	str_printf_v(cadena_p4_a);
	printf("%i ---\n",test4);
	str_printf_v(cadena_p4_b);
	printf("-\n\n");

}


/*
INSERTADO
*/
void test_insertado(){

//1: Insertado al principio
	int tam_p1_a = 2, tam_p1_b = 2; 
	struct iovec p1_a[tam_p1_a];
	struct iovec p1_b[tam_p1_b];

	p1_a[0].iov_base = "-inser";
	p1_a[0].iov_len = strlen("-inser");
	p1_a[1].iov_base = "cion-";
	p1_a[1].iov_len = strlen("cion-");

	p1_b[0].iov_base = "hello ";
	p1_b[0].iov_len = strlen("hello ");
	p1_b[1].iov_base = "world\n";
	p1_b[1].iov_len = strlen("world\n");

	cadena * cadena_p1_a = crear_cadena(p1_a,tam_p1_a);
	cadena * cadena_p1_b = crear_cadena(p1_b,tam_p1_b);

	printf("1- Insertado al principio:\n");
	str_printf_v(cadena_p1_b);

	cadena_p1_b = str_insert_v(0,cadena_p1_b,cadena_p1_a);
	if (test_error(cadena_p1_b))
		exit(0);

	printf("-----\n");
	str_printf_v(cadena_p1_b);
	printf("-\n\n");

//2: Insertado al principio de un nodo intermedio
	int tam_p2_a = 2, tam_p2_b = 3; 
	struct iovec p2_a[tam_p2_a];
	struct iovec p2_b[tam_p2_b];

	p2_a[0].iov_base = "-inser";
	p2_a[0].iov_len = strlen("-inser");
	p2_a[1].iov_base = "cion-";
	p2_a[1].iov_len = strlen("cion-");

	p2_b[0].iov_base = "hello ";
	p2_b[0].iov_len = strlen("hello ");
	p2_b[1].iov_base = "wor";
	p2_b[1].iov_len = strlen("wor");
	p2_b[2].iov_base = "ld\n";
	p2_b[2].iov_len = strlen("ld\n");

	cadena * cadena_p2_a = crear_cadena(p2_a,tam_p2_a);
	cadena * cadena_p2_b = crear_cadena(p2_b,tam_p2_b);

	printf("2- Insertado al principio de un nodo intermedio:\n");
	str_printf_v(cadena_p2_b);
	printf("-----\n");

	cadena_p2_b = str_insert_v(6,cadena_p2_b,cadena_p2_a);
	if (test_error(cadena_p2_b))
		exit(0);

	str_printf_v(cadena_p2_b);
	printf("-\n\n");

//3: Insertado al final de un nodo intermedio
	int tam_p3_a = 2, tam_p3_b = 3; 
	struct iovec p3_a[tam_p3_a];
	struct iovec p3_b[tam_p3_b];

	p3_a[0].iov_base = "-inser";
	p3_a[0].iov_len = strlen("-inser");
	p3_a[1].iov_base = "cion-";
	p3_a[1].iov_len = strlen("cion-");

	p3_b[0].iov_base = "hello ";
	p3_b[0].iov_len = strlen("hello ");
	p3_b[1].iov_base = "world";
	p3_b[1].iov_len = strlen("world");
	p3_b[2].iov_base = "next\n";
	p3_b[2].iov_len = strlen("next\n");

	cadena * cadena_p3_a = crear_cadena(p3_a,tam_p3_a);
	cadena * cadena_p3_b = crear_cadena(p3_b,tam_p3_b);

	printf("3- Insertado al final de un nodo intermedio:\n");
	str_printf_v(cadena_p3_b);
	printf("-----\n");

	cadena_p3_b = str_insert_v(11,cadena_p3_b,cadena_p3_a);
	if (test_error(cadena_p3_b))
		exit(0);

	str_printf_v(cadena_p3_b);
	printf("-\n\n");

//4: Insertado en el medio de un nodo intermedio	
	int tam_p4_a = 2, tam_p4_b = 3; 
	struct iovec p4_a[tam_p4_a];
	struct iovec p4_b[tam_p4_b];

	p4_a[0].iov_base = "-inser";
	p4_a[0].iov_len = strlen("-inser");
	p4_a[1].iov_base = "cion-";
	p4_a[1].iov_len = strlen("cion-");

	p4_b[0].iov_base = "hello ";
	p4_b[0].iov_len = strlen("hello ");
	p4_b[1].iov_base = "wor";
	p4_b[1].iov_len = strlen("wor");
	p4_b[2].iov_base = "ld\n";
	p4_b[2].iov_len = strlen("ld\n");

	cadena * cadena_p4_a = crear_cadena(p4_a,tam_p4_a);
	cadena * cadena_p4_b = crear_cadena(p4_b,tam_p4_b);

	printf("4- Insertado en el medio de un nodo intermedio:\n");
	str_printf_v(cadena_p4_b);
	printf("-----\n");

	cadena_p4_b = str_insert_v(7,cadena_p4_b,cadena_p4_a);
	if (test_error(cadena_p4_b))
		exit(0);

	str_printf_v(cadena_p4_b);
	printf("-\n\n");

//5: Insertado al final
	int tam_p5_a = 2, tam_p5_b = 3; 
	struct iovec p5_a[tam_p5_a];
	struct iovec p5_b[tam_p5_b];

	p5_a[0].iov_base = "-inser";
	p5_a[0].iov_len = strlen("-inser");
	p5_a[1].iov_base = "cion-";
	p5_a[1].iov_len = strlen("cion-");

	p5_b[0].iov_base = "hello ";
	p5_b[0].iov_len = strlen("hello ");
	p5_b[1].iov_base = "wor";
	p5_b[1].iov_len = strlen("wor");
	p5_b[2].iov_base = "ld\n";
	p5_b[2].iov_len = strlen("ld\n");

	cadena * cadena_p5_a = crear_cadena(p5_a,tam_p5_a);
	cadena * cadena_p5_b = crear_cadena(p5_b,tam_p5_b);

	printf("5- Insertado al final:\n");
	str_printf_v(cadena_p5_b);
	printf("-----\n");

	cadena_p5_b = str_insert_v(12,cadena_p5_b,cadena_p5_a);
	if (test_error(cadena_p5_b))
		exit(0);

	str_printf_v(cadena_p5_b);
	printf("\n-\n\n");
}


/*
BORRADO
*/
void test_borrado(){

	//Borrado dentro de un nodo
	int tam_p1 = 2;
	struct iovec p1[tam_p1];

	p1[0].iov_base = "hello ";
	p1[0].iov_len = strlen("hello ");
	p1[1].iov_base = "world\n";
	p1[1].iov_len = strlen("world\n");

	cadena * cadena_p1 = crear_cadena(p1,tam_p1);
	cadena * cadena_salida1;

	printf("1- Borrado dentro de un nodo:\n");
	str_printf_v(cadena_p1);
	printf("-----\n");

	cadena_salida1 = str_delete_v(cadena_p1,1,3);
	if (test_error(cadena_salida1))
		exit(0);

	str_printf_v(cadena_salida1);
	printf("-\n\n");

	//Borrado del final de un nodo y principio del siguiente
	int tam_p2 = 2;
	struct iovec p2[tam_p2];

	p2[0].iov_base = "hello ";
	p2[0].iov_len = strlen("hello ");
	p2[1].iov_base = "world\n";
	p2[1].iov_len = strlen("world\n");

	cadena * cadena_p2 = crear_cadena(p2,tam_p2);
	cadena * cadena_salida2;

	printf("2- Borrado del final de un nodo y principio del siguiente:\n");
	str_printf_v(cadena_p2);
	printf("-----\n");

	cadena_salida2 = str_delete_v(cadena_p2,3,8);
	if (test_error(cadena_salida2))
		exit(0);

	str_printf_v(cadena_salida2);
	printf("-\n\n");

	//Borrado del primer nodo completo
	int tam_p3 = 2;
	struct iovec p3[tam_p3];

	p3[0].iov_base = "hello ";
	p3[0].iov_len = strlen("hello ");
	p3[1].iov_base = "world\n";
	p3[1].iov_len = strlen("world\n");

	cadena * cadena_p3 = crear_cadena(p3,tam_p3);
	cadena * cadena_salida3;

	printf("3- Borrado del primer nodo completo:\n");
	str_printf_v(cadena_p3);
	printf("-----\n");

	cadena_salida3 = str_delete_v(cadena_p3,0,6);
	if (test_error(cadena_salida3))
		exit(0);

	str_printf_v(cadena_salida3);
	printf("-\n\n");

	//Borrado del único nodo
	int tam_p4 = 1;
	struct iovec p4[tam_p4];

	p4[0].iov_base = "hello ";
	p4[0].iov_len = strlen("hello ");

	cadena * cadena_p4 = crear_cadena(p4,tam_p4);
	cadena * cadena_salida4;

	printf("4- Borrado del único nodo:\n");
	str_printf_v(cadena_p4);
	printf("\n-----\n");

	cadena_salida4 = str_delete_v(cadena_p4,0,6);
	if (test_error(cadena_salida4))
		exit(0);

	str_printf_v(cadena_salida4);
	printf("-\n\n");

	//Borrado del ultimo nodo completo
	int tam_p5 = 2;
	struct iovec p5[tam_p5];

	p5[0].iov_base = "hello ";
	p5[0].iov_len = strlen("hello ");
	p5[1].iov_base = "world\n";
	p5[1].iov_len = strlen("world\n");

	cadena * cadena_p5 = crear_cadena(p5,tam_p5);
	cadena * cadena_salida5;

	printf("5- Borrado del ultimo nodo completo:\n");
	str_printf_v(cadena_p5);
	printf("-----\n");

	cadena_salida5 = str_delete_v(cadena_p5,6,12);
	if (test_error(cadena_salida5))
		exit(0);

	str_printf_v(cadena_salida5);
	printf("-\n\n");

	//Borrado de 2 nodos completos
	int tam_p6 = 3;
	struct iovec p6[tam_p6];

	p6[0].iov_base = "hello ";
	p6[0].iov_len = strlen("hello ");
	p6[1].iov_base = "world\n";
	p6[1].iov_len = strlen("world\n");
	p6[2].iov_base = "next\n";
	p6[2].iov_len = strlen("next\n");

	cadena * cadena_p6 = crear_cadena(p6,tam_p6);
	cadena * cadena_salida6;

	printf("6- Borrado de 2 nodos completos:\n");
	str_printf_v(cadena_p6);
	printf("-----\n");

	cadena_salida6 = str_delete_v(cadena_p6,0,12);
	if (test_error(cadena_salida6))
		exit(0);

	str_printf_v(cadena_salida6);
	printf("-\n\n");

}


/*
STR_DUP_V
*/
void test_str_dup(){

	int tam_o = 2,tam_d = 2;
	struct iovec origen[tam_o];
	struct iovec destino[tam_d];
	origen[0].iov_base = "hello ";
	origen[0].iov_len = strlen("hello ");
	origen[1].iov_base = "world";
	origen[1].iov_len = strlen("world");

	cadena * cadena_origen = crear_cadena(origen,tam_o);
	cadena * cadena_destino = (cadena *) malloc (sizeof(cadena_origen));

	printf("\n");
	str_printf_v(cadena_origen);
	printf("\n");
	str_printf_v(cadena_destino);

	cadena_destino = str_dup_v(cadena_origen);
	if (test_error(cadena_destino))
		exit(0);

	printf("\n-----\n");
	str_printf_v(cadena_destino);
	printf("\n-\n\n");
}


/*
CONCATENADO
*/
void test_concatenado(){

	int tam_o = 2,tam_d = 2;
	struct iovec origen[tam_o];
	struct iovec destino[tam_d];
	destino[0].iov_base = "hello ";
	destino[0].iov_len = strlen("hello ");
	destino[1].iov_base = "world";
	destino[1].iov_len = strlen("world");
	origen[0].iov_base = "next ";
	origen[0].iov_len = strlen("next ");
	origen[1].iov_base = "text";
	origen[1].iov_len = strlen("text");

	cadena * cadena_origen = crear_cadena(origen,tam_o);
	cadena * cadena_destino = crear_cadena(destino,tam_d);

	printf("\n");
	str_printf_v(cadena_origen);
	printf("\n");
	str_printf_v(cadena_destino);

	cadena_destino = str_cat_v(cadena_destino, cadena_origen);
	if (test_error(cadena_destino))
		exit(0);

	printf("\n-----\n");
	str_printf_v(cadena_destino);
	printf("\n-\n\n");
}



/*
* INSERTADO CON SOBRESCRITURA
*/
void test_insert_over(){

//1: Insertado con el tamaño del segundo nodo exactamente
	int tam_o1 = 1,tam_d1 = 2;
	struct iovec origen1[tam_o1];
	struct iovec destino1[tam_d1];
	destino1[0].iov_base = "hello ";
	destino1[0].iov_len = strlen("hello ");
	destino1[1].iov_base = "world";
	destino1[1].iov_len = strlen("world");
	origen1[0].iov_base = "-ins-";
	origen1[0].iov_len = strlen("-ins-");
	
	cadena * cadena_origen1 = crear_cadena(origen1,tam_o1);
	cadena * cadena_destino1 = crear_cadena(destino1,tam_d1);
	
	printf("1- Copia el tamaño del segundo nodo exactamente.\n");
	str_printf_v(cadena_destino1);
	
	cadena_destino1 = insert_over(6,cadena_destino1,cadena_origen1);
	if (test_error(cadena_destino1))
		exit(0);

	printf("\n-----\n");
	str_printf_v(cadena_destino1);
	printf("\n-\n\n");

//2: Insertado entre dos nodos
	int tam_o2 = 2,tam_d2 = 2;
	struct iovec origen2[tam_o2];
	struct iovec destino2[tam_d2];
	destino2[0].iov_base = "hello ";
	destino2[0].iov_len = strlen("hello ");
	destino2[1].iov_base = "world";
	destino2[1].iov_len = strlen("world");
	origen2[0].iov_base = "-inser";
	origen2[0].iov_len = strlen("-inser");
	origen2[1].iov_base = "cion-";
	origen2[1].iov_len = strlen("cion-");
	
	cadena * cadena_origen2 = crear_cadena(origen2,tam_o2);
	cadena * cadena_destino2 = crear_cadena(destino2,tam_d2);

	printf("2- Copia entre dos nodos.\n");
	str_printf_v(cadena_destino2);
	
	cadena_destino2 = insert_over(3,cadena_destino2,cadena_origen2);
	if (test_error(cadena_destino2))
		exit(0);

	printf("\n-----\n");
	str_printf_v(cadena_destino2);
	printf("\n-\n\n");

//3: Insertado al principio
	int tam_o3 = 1,tam_d3 = 2;
	struct iovec origen3[tam_o3];
	struct iovec destino3[tam_d3];
	destino3[0].iov_base = "hello ";
	destino3[0].iov_len = strlen("hello ");
	destino3[1].iov_base = "world";
	destino3[1].iov_len = strlen("world");
	origen3[0].iov_base = "-i-";
	origen3[0].iov_len = strlen("-i-");
	
	cadena * cadena_origen3 = crear_cadena(origen3,tam_o3);
	cadena * cadena_destino3 = crear_cadena(destino3,tam_d3);

	printf("3- Copia en la primera posición.\n");
	str_printf_v(cadena_destino3);
	
	cadena_destino3 = insert_over(0,cadena_destino3,cadena_origen3);
	if (test_error(cadena_destino3))
		exit(0);

	printf("\n-----\n");
	str_printf_v(cadena_destino3);
	printf("\n-\n\n");

//4: Insertado al final
	int tam_o4 = 1,tam_d4 = 2;
	struct iovec origen4[tam_o4];
	struct iovec destino4[tam_d4];
	destino4[0].iov_base = "hello ";
	destino4[0].iov_len = strlen("hello ");
	destino4[1].iov_base = "world";
	destino4[1].iov_len = strlen("world");
	origen4[0].iov_base = "-i-";
	origen4[0].iov_len = strlen("-i-");
	
	cadena * cadena_origen4 = crear_cadena(origen4,tam_o4);
	cadena * cadena_destino4 = crear_cadena(destino4,tam_d4);

	printf("4- Copia en la ultima posición.\n");
	str_printf_v(cadena_destino4);
	
	cadena_destino4 = insert_over(10,cadena_destino4,cadena_origen4);
	if (test_error(cadena_destino4))
		exit(0);

	printf("\n-----\n");
	str_printf_v(cadena_destino4);
	printf("\n-\n\n");

}

int main(){

	char intro[1];


	system("clear");

	printf("COMPARACION\n\n");
	test_comparacion();

	scanf("%c",intro);
	system("clear");

	printf("INSERTADO\n\n");
	test_insertado();

	scanf("%c",intro);
	system("clear");

	printf("BORRADO\n\n");
	test_borrado();

	scanf("%c",intro);
	system("clear");

	printf("COPIA\n\n");
	test_str_dup();

	scanf("%c",intro);
	system("clear");

	printf("CONCATENADO\n\n");
	test_concatenado();

	scanf("%c",intro);
	system("clear");

	printf("INSERTAR CON SOBREESCRITURA\n\n");
	test_insert_over();

}








