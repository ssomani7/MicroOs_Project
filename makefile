C_SOURCES = $(wildcard kernel/*.c drivers/*.c lib/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)

OBJ = ${C_SOURCES:.c=.o}
all: os-image

run: all
	bochs
os-image: boot/bootsect.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel/kernel_entry.o ${OBJ}
	ld -melf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c ${ HEADERS }
	gcc -m32 -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -I 'boot/'  -o $@

clean:
	rm -fr *.bin *.dis *.o os-image
	rm -fr kernel/*. o boot/*.bin drivers/*.o
