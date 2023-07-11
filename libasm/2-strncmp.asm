BITS 64

global asm_strncmp

asm_strncmp:
xor rax, rax
mov rbx, rdi
mov rcx, rsi
mov rdx, rdx


loop_start:
cmp rdx, 0
je end
mov al, byte [rbx]
mov dl, byte [rcx]
cmp al, 0
je first_null
cmp dl, 0
je sec_null
cmp al, dl
jl less_than
jg greater_than
inc rbx
inc rcx
dec rdx
jmp loop_start

first_null:
cmp al, dl
jne less_than
je end

sec_null:
cmp al, dl
jne greater_than
je end

less_than:
mov rax, 1
jmp end

greater_than:
mov rax, -1
jmp end

end:
ret