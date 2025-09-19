[org 0x7C00]
bits 16

start:
    mov ax, 0x07C0
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    call clear_screen
    call show_boot_menu

    mov ah, 0x00
    int 0x16

    cmp al, '1'
    je load_from_disk
    cmp al, '2'
    je load_from_usb
    jmp start

load_from_usb:
    mov cl, 3
    jmp load_kernel

load_from_disk:
    mov cl, 2

load_kernel:
    mov ah, 0x02
    mov al, 30
    mov ch, 0
    mov dh, 0
    mov bx, 0x1000
    int 0x13

    jc disk_error

    mov si, success_msg
    call print_string

    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp 0x08:protected_mode

disk_error:
    mov si, error_msg
    call print_string
    jmp $

clear_screen:
    mov ah, 0x07
    mov al, 0x00
    mov bh, 0x07
    mov cx, 0x0000
    mov dx, 0x184F
    int 0x10
    ret

show_boot_menu:
    mov si, boot_menu
    call print_string
    ret

print_string:
    mov ah, 0x0E
.next_char:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .next_char
.done:
    ret

bits 32
protected_mode:
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    jmp 0x1000

boot_menu db "Select boot device:", 13, 10
          db "1. Hard Disk", 13, 10
          db "2. USB", 13, 10
          db "Press 1 or 2: ", 0

error_msg db "Disk error! System halted.", 0
success_msg db "Kernel loaded successfully!", 0

gdt:
    dq 0x0000000000000000
    dq 0x00CF9A000000FFFF
    dq 0x00CF92000000FFFF

gdt_descriptor:
    dw 23
    dd gdt

times 510-($-$$) db 0
dw 0xAA55
