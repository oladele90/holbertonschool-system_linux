BITS 64

global asm_strncasecmp

section .text
asm_strncasecmp:
mov rcx, rdx
loop_start:
cmp rcx, 0
je return_calc
mov rax, rdi
mov rdx, rsi
movzx eax, BYTE [rax]
movzx edx, BYTE [rdx]
cmp al, 0
jne null_checker
cmp dl, 0
je return_calc
null_checker:
cmp al, 65
jl switch_lower
cmp al, 90
jg switch_lower
add ax, 32
switch_lower:
cmp dl, 65
jl increment
cmp dl, 90
jg increment
add dx, 32

increment:
cmp al, dl
jne return_calc
inc rdi
inc rsi
dec rcx
jmp loop_start
return_calc:
cmp al, dl
je equal
jl less
sub al, dl
jmp end
equal:
mov rax, 0
jmp end
less:
sub al, dl
neg al
imul eax, -1
jmp end
end:
ret