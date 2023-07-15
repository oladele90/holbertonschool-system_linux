BITS 64

global asm_putc

asm_putc:
        push rdi
        mov rax, 1
        mov rdx, 1
        mov rdi, 1
        mov rsi, rsp
        syscall
end:
        pop  rdi
        ret