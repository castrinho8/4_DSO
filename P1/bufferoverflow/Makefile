#
#

all: over ret print
	
over:
	gcc -fno-stack-protector -o overflow buffer_overflow.c 

ret:
	gcc -o retorno modificar_retorno.c 

print:
	gcc -o print print_file_stack.c

clean:
	rm -f *.o overflow retorno print stack.bin

