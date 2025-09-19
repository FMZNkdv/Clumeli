void _start() {
    char* vga = (char*)0xB8000;

    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        vga[i] = ' ';
        vga[i+1] = 0x07;
    }

    vga[0] = '>';
    vga[1] = 0x07;
    vga[2] = ' ';
    vga[3] = 0x07;

    while(1);
}
