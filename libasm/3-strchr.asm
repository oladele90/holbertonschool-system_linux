BITS 64

global asm_strchr

asm_strchr:
mov rax, rdi
movzx ecx, dil

loop_start:
cmp byte [rax], cl
je match
cmp byte [rax], 0
je end
inc rax
jmp loop_start

match:
ret

end:
xor rax, rax
ret