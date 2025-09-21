Clumeli is a custom-built operating system with its own bootloader written in Assembly and kernel written in C. It features a minimalistic design with custom commands and a simple shell interface.

## Features

- Custom bootloader with device selection menu
- Minimal kernel written in C
- Basic command-line interface
- Support for multiple boot devices (HDD/USB)
- Custom commands (echo, clear, ls, help, etc.)

## Build Requirements

- NASM (Netwide Assembler)
- GCC (GNU Compiler Collection)
- GNU Make
- genisoimage (for creating ISO images)

### Install Dependencies

**Ubuntu/Debian:**
```bash
sudo apt install nasm gcc make genisoimage
```

**Arch Linux:**
```bash
sudo pacman -S nasm gcc make cdrkit
```

## Building the System

1. Clone or download the project files
   ```bash
   git clone https://github.com/FMZNKdv/Clumeli
   cd Clumeli
   ```
3. Make the build script executable:
   ```bash
   chmod +x build.sh
   ```
4. Run the build script:
   ```bash
   ./build.sh
   ```

The build process will:
- Compile the bootloader (boot.bin)
- Compile the kernel (kernel.bin)
- Create a disk image (disk.img)
- Create an ISO image (myos.iso)
- Place all final images in the `images/` directory

## Disclaimer

This is an educational project and not intended for production use. Use at your own risk.
