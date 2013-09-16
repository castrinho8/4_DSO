# Practica 2 -DSO
# Pablo Castro Valiño ( pablo.castro1@udc.es ).

#Compilador.
COMP = gcc


all: test
	
test:
	$(COMP) -o tests_tiempo tests_tiempos.c -lm -g
	$(COMP) -o tests_funcionamiento tests_funcionamiento.c -g

clean:
	rm -f *.o tests_tiempo tests_funcionamiento cadena_lib.o strings_lib.o tiempos_lib.o old_strings_lib.o

tar: clean
	tar czvf p2.tar.gz Makefile cadena_lib.c old_strings_lib.c strings_lib.c tiempos_lib.c  tests_tiempos.c tests_funcionamiento.c  memoriap2.pdf


