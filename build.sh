#!/bin/bash

mkdir -p output
mkdir -p images
mkdir -p initrd_root/bin
echo "Compiling bootloader..."
nasm -f bin boot.asm -o output/boot.bin
echo "Compiling kernel..."
gcc -ffreestanding -nostdlib -c kernel.c -o output/kernel.o
ld -T linker.ld -o output/kernel.bin output/kernel.o --oformat binary
echo "Creating initrd..."
echo '#!/bin/sh' > initrd_root/init
echo 'echo "Welcome!"' >> initrd_root/init
echo 'export PATH=/bin' >> initrd_root/init
echo 'while true; do' >> initrd_root/init
echo '    echo -n "# "' >> initrd_root/init
echo '    read command' >> initrd_root/init
echo '    $command' >> initrd_root/init
echo 'done' >> initrd_root/init
chmod +x initrd_root/init
cd initrd_root
find . -print0 | cpio -o -H newc > ../output/initrd.img
cd ..
echo "Creating disk image..."
dd if=/dev/zero of=images/disk.img bs=1M count=10 2>/dev/null
echo "Writing bootloader..."
dd if=output/boot.bin of=images/disk.img conv=notrunc 2>/dev/null
echo "Writing kernel..."
dd if=output/kernel.bin of=images/disk.img seek=1 conv=notrunc 2>/dev/null
echo "Writing initrd..."
dd if=output/initrd.img of=images/disk.img seek=100 conv=notrunc 2>/dev/null
echo "Creating ISO image..."
mkdir -p output/iso
cp images/disk.img output/iso/
genisoimage -o images/core.iso -b disk.img -no-emul-boot output/iso/ 2>/dev/null
echo "Build complete! Files are in images/ directory."
echo "Disk image: images/disk.img"
echo "ISO image: images/core.iso"
