# Practica 4 -DSO
# Pablo Castro Valiño ( pablo.castro1@udc.es ).

#Compilacion de ficheros

COMP=gcc
MODCFLAGS := -O -Wall -DMODULE -D__KERNEL__

tail: tail_module.o cola.o
	ld -m elf_i386 -r -o modulo.o tail_module.o cola.o

tail_module.o: cola.o
	$(COMP) ${MODCFLAGS} -c tail_module.c

cola.o:
	$(COMP) ${MODCFLAGS} -c Cola.c 

