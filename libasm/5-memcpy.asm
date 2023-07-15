BITS 64

global asm_memcpy

asm_memcpy:
push rdi

loop_start:
test rdx, rdx
jz end
mov al, byte [rsi]
mov byte [rdi], al
inc rdi
inc rsi
dec rdx
jmp loop_start

end:
pop rax
ret