void _start() {
    char* vga = (char*)0xB8000;
    char* msg = "Hello from echo!\n";

    for (int i = 0; msg[i]; i++) {
        vga[i*2] = msg[i];
        vga[i*2+1] = 0x07;
    }

    while(1);
}
