BITS 64

global asm_strstr

asm_strstr:
push rdi
push rsi
xor rax, rax
xor rsi, rsi
xor rcx, rcx
mov rsi, [rsp]
mov rdx, rdi
cmp [rsi], byte 0
je needle_null
cmp [rdi], byte 0
je end



loop_start:
movzx r8, byte [rdi + rcx]
movzx r9, byte [rsi + rcx]

cmp r8b, byte 0
je needle_null

cmp r9b, byte 0
jz needle_null

cmp r8, r9
je counter
inc rdi
xor rcx, rcx
jmp loop_start

counter:
inc rcx
jmp loop_start

needle_null:
test r9b, r9b
jnz end
mov rax, rdi

end:
pop rsi
pop rdi
ret