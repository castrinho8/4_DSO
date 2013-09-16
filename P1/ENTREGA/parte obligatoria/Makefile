# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

all: tests espacial temporal
	
# Compila los ficheros de test para ver como se organiza el stack
tests:
	gcc -o test1 test1-programa_basico.c 
	gcc -o test2 test2-programa_argumentos.c

# Compila ficheros para realizar el salto espacial en el stack
espacial:
	gcc -o distancia distancia_salto.c 
	gcc -o espacial salto_espacial.c 

# Compila ficheros para realizar el salto temporal en el stack
temporal:
	gcc -o temporal salto_temporal.c

# Elimina ficheros ejecutables y generados
clean:
	rm -f *.o test1 test2 distancia espacial temporal
