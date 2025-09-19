int main() {
    print_string("Rebooting system...", 0x0C);
    asm volatile("int $0x19");
    return 0;
}
