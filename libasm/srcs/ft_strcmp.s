section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax				; Initialize return value to 0
	xor rcx, rcx				; Initialize index counter to 0

_loop:
	mov al, BYTE [rdi + rcx]	; Load the current byte from the first string into AL
	mov bl, BYTE [rsi + rcx]	; Load the current byte from the second string into BL
	cmp al, bl					; Compare the two bytes
	jne _not_equal				; If they are not equal, jump to the not_equal label
	cmp al, 0					; Check if we have reached the null terminator
	je _return					; If it is, go to the return label (strings are equal)
	inc rcx						; Increment the index counter
	jmp _loop					; Jump back to loop

_not_equal:
	movzx rax, al				; Move the byte from AL to RAX and zero-extend it
	movzx rbx, bl				; Move the byte from BL to RBX and zero-extend it
	sub rax, rbx				; Subtract the second byte from the first byte to get the return value
	jmp _return					; Jump to the return label

_return:
	ret

; Mark stack as non-executable
section .note.GNU-stack
