#!/bin/sh

profan_path="../profanOS"
CFLAGS="-ffreestanding -fno-exceptions -m32 -I$profan_path/include/zlibs -O1 -nostdinc"
LDFLAGS="-m elf_i386 -nostdlib -L $profan_path/out/zlibs -T $profan_path/tools/link_elf.ld -lc"

mkdir -p build
gcc -c gameboy.c -o build/o1.o $CFLAGS
gcc -c platform.c -o build/o2.o $CFLAGS
gcc -c minisdl.c -o build/o3.o $CFLAGS

ld $LDFLAGS -o gameboy.elf build/o1.o build/o2.o build/o3.o
