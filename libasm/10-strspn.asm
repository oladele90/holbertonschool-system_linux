BITS 64

global asm_strspn

asm_strspn:
mov rcx, 0
mov r8, 0

count1:
	cmp byte [rdi + rcx], 0
	je end

	mov rbx, 0
count2:
	mov r8b, [rsi + rbx]
	cmp r8b, 0
	je end

	inc rbx
	cmp r8b, [rdi + rcx]
	jne count2

	inc rcx
	jmp count1

end:
	mov rax, rcx
	ret	