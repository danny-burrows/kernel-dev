;;kernel.asm
bits 32                     ; NASM directive: Run in 32 bit mode.
section .text
        ;multiboot spec...
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero

global start                ; The code segment
extern kmain                ; kmain is defined in kernal.c.

start:
    cli                     ; Stands for clear interupts, blocks them.
    mov esp, stack_base     ; Move the stack pointer to the base of the stack.
    call kmain
    hlt                     ; Halt the cpu.

section .bss                ; Block starting symbol: Section for staticly allocated variables.
resb 8192                   ; Reserve Bytes: 8KB reserved for the stack.
stack_base:                 ; Label denoting the bottom of the stack.