/*
# Pablo Castro Valiño (pablo.castro1@udc.es)
# Deseño de Sistemas Operativos

Device driver que funciona como una cola de caracteres de un tamaño
máximo al que es inicializada y en el cual entran y salen elementos
en orden.


Links interesantes:
http://www.linuxjournal.com/article/2920 registrar drivers
http://www.ibm.com/developerworks/linux/library/l-kernel-memory-access/index.html

*/

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <linux/time.h>
#include "Cola.h"

#define __NO_VERSION__     /* It's not THE file of the kernel module */

static tCola * cola shared_buffer;

//Funcion de lectura
static ssize_t device_read(struct file * fichero, char * read_buffer, size_t length, loff_t * offset){

	int count = 0;
	char * item = kmalloc(sizeof(char));
	time_t t = time(NULL);	

	for (count=0;count<length;count++){

		item = eliminar_primero(cola);

		if(copy_to_user(read_buffer+count,item,sizeof(char))){
			return -EINVAL;
		}

		//mostrarCola(cola);
		
		printk ("Termino de quitar el item %c a las %s",item, ctime(&t));
	}
	*offset = count;
	return count;
}


static ssize_t device_write(struct file * fichero, const char * write_buffer, size_t length, loff_t * offset){

	int count = 0;
	char * item = kmalloc(sizeof(char));
	time_t t = time(NULL);		

	for (count=0;count<length;count++){
	
		if(copy_from_user(item,write_buffer+count,sizeof(char))){
			return -EINVAL;
		}

		insertar(item, cola);//anñade el item producido al buffer compartido mostrarBuffer();
		
		//mostrarCola(cola);

		printk("Añadido %c a las %s" ,item, ctime(&t));

	}
	*offset = count;
	return count;
}


//Estructura de las operaciones
static const struct file_operations sem_module_fops =
{
	.owner = THIS_MODULE,
	.read  = device_read,
	.write = device_write,
};

//Estructura del driver
static struct miscdevice sem_module_device = 
{
	MISC_DYNAMIC_MINOR,
	"tail_module",
	&sem_module_fops,

};


static int __init tail_module_init(void){
	int ret=0;

	printk("-----------\nIniciando módulo con buffer de tamaño %i caracteres.\n",TAM_BUFFER);

	tCola * cola shared_buffer;

	shared_buffer = kmalloc(TAM_BUFFER * sizeof(tCola), GFP_KERNEL);
	if (!shared_buffer){
		printk(KERN_ERR "Error reservando memoria para el buffer.\n");
		exit(EXIT_FAILURE);
	}

	crear_cola (tCola * cola,TAM_BUFFER);

	if((ret=misc_register(&tail_module_device)))
		printk(KERN_ERR "No se pudo registrar el módulo\n");
	
	return ret;
}

static void __init tail_module_exit (void){

	printk("Desinstalando módulo\n-----------\n");
	misc_deregister(&tail_module_device);
}


module_init(tail_module_init);
module_exit(tail_module_exit);

MODULE_AUTHOR("Pablo Castro Valiño");
MODULE_DESCRIPTION("Módulo que tiene una cola de un tamaño definido en la que se guardan y extraen caracteres.");
MODULE_VERSION("dev");
