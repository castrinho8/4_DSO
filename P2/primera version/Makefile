# Practica 2 -DSO
# Pablo Castro Valiño ( pablo.castro1@udc.es ).

#Compilador.
COMP = gcc


all: test
	
# Compila los ficheros para realizar los test de tiempo y de funcionamiento
test:
	$(COMP) -o tests_tiempo tests_tiempos.c -lm
	$(COMP) -o tests_funcionamiento tests_funcionamiento.c

# Elimina los ficheros ejecutables y generados
clean:
	rm -f *.o tests_tiempo tests_funcionamiento cadena_lib.o strings_lib.o tiempos_lib.o old_strings_lib.o

# Comprime en un tar para su entrega
tar: clean
	tar czvf p2.tar.gz strings_lib.c tiempos_lib.c cadena_lib.c tests_tiempos.c tests_funcionamiento.c 


