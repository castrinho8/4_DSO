#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <aio.h>

//gcc -fno-stack-protector -g programa2.c

int startt2 = 1;
int ct = 0;
int mf = 1;
int tf[2]; //frame de t1
int tr[2]; //return de t1
char mensaje[100];

//aio_read(0);

//Función que realentiza realizando cálculos inutiles	
void slow(){
	int i;
	long a;
	for(i=1;i<100000;i++)
		a = 200*4000/23;
}

yield(){
	int a[10];
		
	tf[ct] = a[13];//frame de t1
	tr[ct] = a[14];//return de t1
	
	if(startt2){
		startt2 = 0;
		t2();
	}
	
	ct = !ct;

	a[13] = tf[ct];
	a[14] = tr[ct];
}

t1(){
	volatile char a[10];
	volatile int i;

	for(i=1;i<10;i++){
		ct = 0;
		sprintf(a,"\ta\n");
		write(1,a,strlen(a));
 		slow();
//		sprintf(a,"Estou en t1 e i == %i\n",i);
//		write(1,a,strlen(a));
		//sprintf(a,"%d  %x %dM",(void *)&mf - (void *)&a,(void *)&ct - (void *)&a,((void *)&mf - (void *)&a) / 1000000);
		//write(1,a,strlen(a));
		yield();
	}
}

t2(){
	volatile char a[10];
	volatile int i;
	
	for(i=1;i<10;i++){
		ct = 1;
		sprintf(a,"\tb\n");
		write(1,a,strlen(a));
 		slow();
//		sprintf(a,"Estou en t2 e i == %i\n",i);
//		write(1,a,strlen(a));
		//sprintf(a,"%d %x",(void *)&mf - (void *)&a,(void *)&ct - (void *)&a);
		//write(1,a,strlen(a));
		yield();
	}
}


int main(){

	int i = 1;
	mf = &i;
	
	t1();
}

















