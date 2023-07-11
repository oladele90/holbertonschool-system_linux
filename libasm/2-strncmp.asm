BITS 64

global asm_strncmp

asm_strncmp:

loop_start:
cmp rdx, 0
je matbh
cmp [rdi], byte 0
je first_null
cmp [rsi], byte 0
je sec_null
mov bl, byte [rdi]
mov bh, byte [rsi]
cmp bl, bh
jl less_than
jg greater_than
inc rdi
inc rsi
dec rdx
jmp loop_start
matbh:
xor rax, rax
jmp end

first_null:
cmp [rsi], byte 0
jne less_than
je end

sec_null:
cmp [rdi], byte 0 
jne greater_than
je end

less_than:
xor rax, rax
mov rax, -1
jmp end

greater_than:
xor rax, rax
mov rax, 1
jmp end

end:
ret