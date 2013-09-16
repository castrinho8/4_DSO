# Practica 3 -DSO
# Pablo Castro Valiño ( pablo.castro1@udc.es ).

#Compilador.
COMP = gcc


all: fact sinc
	
# Compila la versión simple que crea 3 threads en espacio de usuario que calculan el factorial
fact:
	$(COMP) -fno-stack-protector -o ej1 factorial.c -lm -g
	
# Compila la versión final de la librería de threads y genera un ejecutable para calcular el factorial de 3 threads
sinc:
	$(COMP) -fno-stack-protector -o ej2 copia_sincro.c -lm -g

# Elimina ficheros ejecutables y generados
clean:
	rm -f *.o ej1 ej2 ej3 entrada.txt salida.txt

# Comprime en un tar para su entrega
tar: clean
	tar czvf p2.tar.gz Makefile factorial.c copia_sincro.c copia_asincro memoria/memoria_p3.pdf


