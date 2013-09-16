# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

all: over ret print
	
# Compila fichero que realiza el buffer overflow
over:
	gcc -fno-stack-protector -o overflow buffer_overflow.c 

# Compila el fichero que sirve para modificar las posiciones del stack
ret:
	gcc -o retorno modificar_retorno.c 

# Compila el fichero que sirve para imprimir el fichero que contiene 
# la copia del nuevo stack modificado
print:
	gcc -o print print_file_stack.c

# Elimina ficheros ejecutables y generados
clean:
	rm -f *.o overflow retorno print stack.bin

