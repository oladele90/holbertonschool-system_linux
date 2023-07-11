BITS 64

global asm_strncmp

asm_strncmp:
xor rax, rax
mov rbx, rdi
mov rcx, rsi
xor r8, r8


loop_start:
cmp rdx, r8
je end
mov al, [rbx]
mov dl, [rcx]
cmp al, 0
je first_null
cmp dl, 0
je sec_null
cmp al, dl
jl less_than
jg greater_than
inc rbx
inc rcx
inc r8
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
sub rax, 1
jmp end

greater_than:
sub rax, -1
jmp end

end:
ret