/*
	Kernel Module Example 1: Random Minus.
	
	Description: It prints random capital letters.
 */

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <linux/time.h>

#define TAM_BLOQUE 100

#define MIN(a,b) a>b ? b : a

/*
 *Function that generates random characters.
 */
char
rand_minus(void)
{
	struct timespec st;

	getnstimeofday(&st);

	return 'a' +  st.tv_nsec % 26;

}

/*
 * Read function.
 * I found some information and examples in this sites:
 *	http://www.tldp.org/LDP/lkmpg/2.4/html/c577.htm
 *	http://linuxdevcenter.com/pub/a/linux/2007/07/05/devhelloworld-a-simple-introduction-to-device-drivers-under-linux.html
 */
static ssize_t
read_func(struct file * ficheiro,// File
		  char * buffer, // Buffer where we must write read what has been read.
		  size_t count,  // Number of bytes to read.
		  loff_t * ppos) // [output parameter] Position in the file (I guess).

{	
	int count_aux,indice_buff=0,i;
	char auxbuffer[TAM_BLOQUE];

	for(count_aux=count; count_aux>0; count_aux-=TAM_BLOQUE)
	{

		for(i=0;i<TAM_BLOQUE;i++)
			auxbuffer[i]= rand_minus();

		if(copy_to_user(buffer+indice_buff,
				auxbuffer,
				MIN(TAM_BLOQUE,count_aux)))
		{
			return -EINVAL;
		}
		indice_buff += MIN(TAM_BLOQUE,count_aux);
	}

	*ppos = count;
	return count;
}

//Operations struct
static const struct file_operations rand_minus_fops =
{
	.owner = THIS_MODULE,
	.read  = read_func,
};

//Device struct
static struct miscdevice rand_minus_dev = 
{
	MISC_DYNAMIC_MINOR,
	"random_minus",
	&rand_minus_fops,

};


//Load function
static int __init
rand_minus_init(void)
{
	int ret=0;

	printk("Rexitrando modulo!!\n");

	if((ret=misc_register(&rand_minus_dev)))
		printk(KERN_ERR "Non se puido rexistrar o modulo.\n");
	
	return ret;
}

//We register load function (this is a MACRO)


//Unload function
static void __init
rand_minus_exit (void)
{
	printk("DeRexitrando modulo!!\n");
	misc_deregister(&rand_minus_dev);
}


module_init(modulo_init);
module_exit(modulo_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marcos Chavarria Teijeiro <marcos.chavarria@udc.es>");
MODULE_DESCRIPTION("It prints random minuscule letters.");
MODULE_VERSION("dev");
