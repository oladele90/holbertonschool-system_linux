BITS 64

global asm_strncmp

asm_strncmp:
xor rax, rax
mov rbx, rdi
mov rcx, rsi


loop_start:
cmp rdx, 0
je match
mov al, byte [rbx]
mov dl, byte [rcx]
cmp al, 0
je first_null
cmp dl, 0
je sec_null
cmp al, dl
jl less_than
jg greater_than
dec rdx
cmp rdx, 0
je match
inc rbx
inc rcx
jmp loop_start

first_null:
cmp al, dl
je match
jmp less_than

sec_null:
cmp al, dl
je match
jmp greater_than

match:
xor rax, rax
jmp end

less_than:
xor rax, rax
inc rax
jmp end

greater_than:
xor rax, rax
dec rax
jmp end

end:
ret