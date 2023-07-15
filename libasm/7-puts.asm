BITS 64

global asm_puts
extern asm_strlen

asm_puts:
        push rdi
        call asm_strlen
        pop rdi
        push rdi
        push rsi
        mov rdx, rax
        mov rax, 1
        mov rsi, rdi
        mov rdi, 1
        syscall
end:
        pop rsi
        pop rdi
        ret