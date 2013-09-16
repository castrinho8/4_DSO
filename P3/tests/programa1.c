#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int ct;
int mf = 1;

void slow(){
	int i;
	long a;
	for(i=1;i<100000;i++)
		a = 200*4000/23;
}

yield(){
	if(ct == 1) t2();
	else t1();
}

t1(){
	int i;
	char a [10];
	for(i=1;i<1000;i++){
		ct = 1;
		sprintf(a,"\t%s\n","a");
		write(1,a,strlen(a));
		//slow();
		sprintf(a,"%d  %x %dM",(void *)&mf - (void *)&a,(void *)&ct - (void *)&a,((void *)&mf - (void *)&a) / 1000000);
		write(1,a,strlen(a));
		yield();
	}
}

t2(){
	int i;
	char a[10];
	for(i=1;i<1000;i++){
		ct = 0;
		sprintf(a,"%s","b");
		write(1,a,strlen(a));
		//slow();
		sprintf(a,"%d %x",(void *)&mf - (void *)&a,(void *)&ct - (void *)&a);
		yield();
	}

}



int main(){

	int i = 1;
	ct = 1;
	mf = &i;
	
	t1();

}

















