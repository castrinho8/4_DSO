#/bin/bash

PWD=`pwd`
cd /usr/src/kernels/3.6.9-2.fc17.x86_64

mkdir -p /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.tmp_versions ;
rm -f /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.tmp_versions/*

test -e /usr/src/kernels/3.6.9-2.fc17.x86_64/Module.symvers || ( \
echo; \
echo "  WARNING: Symbol version dump /usr/src/kernels/3.6.9-2.fc17.x86_64/Module.symvers"; \
echo "           is missing; modules will have no dependencies and modversions."; \
echo )


{ echo /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.ko; echo /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.o; } > /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.tmp_versions/rand_minus_mod.mod
(cat /dev/null;  echo kernel//home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.ko;) > /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/modules.order


echo '  Building modules, stage 2.';
echo '  MODPOST 1 modules';
scripts/mod/modpost   -i /usr/src/kernels/3.6.9-2.fc17.x86_64/Module.symvers -I /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/Module.symvers  -o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/Module.symvers -S -w  -s  /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.o

set -e;
echo '  CC      /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.o';
gcc \
	-Wp,-MD,/home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.mod.o.d  \
	-nostdinc \
	-isystem /usr/lib/gcc/x86_64-redhat-linux/4.7.2/include \
	-I/usr/src/kernels/3.6.9-2.fc17.x86_64/arch/x86/include \
	-Iarch/x86/include/generated \
	-Iinclude  \
	-include /usr/src/kernels/3.6.9-2.fc17.x86_64/include/linux/kconfig.h \
	-D__KERNEL__ \
	-Wall \
	-Wundef \
	-Wstrict-prototypes \
	-Wno-trigraphs \
	-fno-strict-aliasing \
	-fno-common \
	-Werror-implicit-function-declaration \
	-Wno-format-security \
	-fno-delete-null-pointer-checks \
	-O2 \
	-m64 \
	-mtune=generic \
	-mno-red-zone \
	-mcmodel=kernel \
	-funit-at-a-time \
	-maccumulate-outgoing-args \
	-fstack-protector \
	-DCONFIG_AS_CFI=1 \
	-DCONFIG_AS_CFI_SIGNAL_FRAME=1 \
	-DCONFIG_AS_CFI_SECTIONS=1 \
	-DCONFIG_AS_FXSAVEQ=1 \
	-DCONFIG_AS_AVX=1 \
	-pipe \
	-Wno-sign-compare \
	-fno-asynchronous-unwind-tables \
	-mno-sse \
	-mno-mmx \
	-mno-sse2 \
	-mno-3dnow \
	-mno-avx \
	-Wframe-larger-than=2048 \
	-Wno-unused-but-set-variable \
	-fno-omit-frame-pointer \
	-fno-optimize-sibling-calls \
	-g \
	-pg \
	-Wdeclaration-after-statement \
	-Wno-pointer-sign \
	-fno-strict-overflow \
	-fconserve-stack \
	-DCC_HAVE_ASM_GOTO  \
	-D"KBUILD_STR(s)=#s" \
	-D"KBUILD_BASENAME=KBUILD_STR(rand_minus_mod.mod)"  \
	-D"KBUILD_MODNAME=KBUILD_STR(rand_minus_mod)" \
	-DMODULE  \
	-c \
	-o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.o \
	/home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.c; scripts/basic/fixdep /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.mod.o.d /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.o 'gcc -Wp,-MD,/home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.mod.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.7.2/include -I/usr/src/kernels/3.6.9-2.fc17.x86_64/arch/x86/include -Iarch/x86/include/generated -Iinclude  -include /usr/src/kernels/3.6.9-2.fc17.x86_64/include/linux/kconfig.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -m64 -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -maccumulate-outgoing-args -fstack-protector -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_AVX=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -Wframe-larger-than=2048 -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(rand_minus_mod.mod)"  -D"KBUILD_MODNAME=KBUILD_STR(rand_minus_mod)" -DMODULE  -c -o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.c' > /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.mod.o.tmp; rm -f /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.mod.o.d; mv -f /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.mod.o.tmp /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.mod.o.cmd

set -e;
echo '  LD [M]  /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.ko'; 

ld \
	-r \
	-m elf_x86_64 \
	-T /usr/src/kernels/3.6.9-2.fc17.x86_64/scripts/module-common.lds \
	--build-id  \
	-o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.ko \
	/home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.o; 

echo 'cmd_/home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.ko := ld -r -m elf_x86_64 -T /usr/src/kernels/3.6.9-2.fc17.x86_64/scripts/module-common.lds --build-id  -o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.ko /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.o /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/rand_minus_mod.mod.o' > /home/ch01/Dropbox/UNI_Fedora/DSO/practica4/rand_minus/.rand_minus_mod.ko.cmd
cd $PWD
