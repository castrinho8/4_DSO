//Cola.c
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <linux/time.h>
#include "Cola.h"


int cola_vacia (tCola *c) {
return (c->num == 0);
}

void crear_cola (tCola *c, int tamanhomax) {
   c->maxNum = tamanhomax;
   c->num = 0;
   c->ppio = 0;
   c->final = -1;
}

void incrementar (int* x, int maxNum) {
   (++*x) % maxNum;
}

void insertar (char x, tCola *c) {
   if (c->num == MAX_ITEMS) printk("\nerror: cola llena: %d", c->num);
   c->num++;
   incrementar (&(c->final), c->maxNum);
   c->items[c->final] = x;
}

char primero (tCola *c) {
	if (cola_vacia (c)) printk("\nError: La cola se encuentra vacia\n");
	else
		return (c->items[c->ppio]);
}


char eliminar_primero (tCola *c) {
   char temp;
	if (cola_vacia (c)) printk("\nError: La cola se encuentra vacia\n");
	else
		c->num--;
		temp = c->items[c->ppio];
		incrementar (&(c->ppio), c->maxNum);
		return temp;
}

void mostrarCola(tCola *c){
	
	char mensaje[300];
	int i = 0 , j = c->final;
	
	incrementar(&j,c->maxNum);
	
	sprintf(mensaje,"La cola tiene %i elementos: <",c->num);
	
	for (i = c->ppio; i != j; incrementar(&i,c->maxNum)) {
		sprintf(mensaje,"%s-%c",mensaje,c->items[i]);
	}
	sprintf(mensaje,"%s <- \n",mensaje);

	printk(mensaje);
}
















