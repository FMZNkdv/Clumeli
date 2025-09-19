#define VGA_ADDRESS 0xB8000
volatile char* vga_buffer = (char*) VGA_ADDRESS;

void clear_screen() {
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        vga_buffer[i] = ' ';
        vga_buffer[i+1] = 0x07;
    }
}

void print_string(const char* str, int color) {
    static int cursor = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            cursor = ((cursor / 160) + 1) * 160;
        } else {
            vga_buffer[cursor] = str[i];
            vga_buffer[cursor+1] = color;
            cursor += 2;
        }
    }
}

void kernel_main() {
    clear_screen();
    print_string("Kernel Loaded Successfully!", 0x0A);
    print_string("\nInitializing system...", 0x07);
    print_string("\n> ", 0x07);

    while(1);
}
