# Practica 3 -DSO
# Pablo Castro Valiño ( pablo.castro1@udc.es ).

#Compilador.
COMP = gcc


all: fact sinc
	
fact:
	$(COMP) -fno-stack-protector -o ej1 factorial.c -lm -g
	
sinc:
	$(COMP) -fno-stack-protector -o ej2 copia_sincro.c -lm -g

clean:
	rm -f *.o ej1 ej2 ej3 entrada.txt salida.txt

tar: clean
	tar czvf p2.tar.gz Makefile factorial.c copia_sincro.c copia_asincro memoria/memoria_p3.pdf


