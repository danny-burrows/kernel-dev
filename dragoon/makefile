tst: ./bin/
	nasm -f elf32 kernel.asm -o ./bin/kasm.o

	i686-elf-gcc -m32 -c kernel.c -o ./bin/kc.o

	i686-elf-ld -m elf_i386 -T link.ld -o ./bin/kernel ./bin/kasm.o ./bin/kc.o

bin/:
	mkdir ./bin
