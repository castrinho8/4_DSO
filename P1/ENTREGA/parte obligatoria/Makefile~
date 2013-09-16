#
#

all: tests espacial temporal
	
tests:
	gcc -o test1 test1-programa_basico.c 
	gcc -o test2 test2-programa_argumentos.c

espacial:
	gcc -o distancia distancia_salto.c 
	gcc -o espacial salto_espacial.c 

temporal:
	gcc -o temporal salto_temporal.c

clean:
	rm -f *.o test1 test2 distancia espacial temporal
