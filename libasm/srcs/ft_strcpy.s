section .text
	global ft_strcpy

ft_strcpy:
	mov rax, rdi				; Copy the destination pointer to RAX to return it later
	xor rcx, rcx				; Initialize index counter to 0	

_loop:
	mov bl, BYTE [rsi + rcx]	; Load the current byte from the source string into BL
	mov BYTE [rdi + rcx], bl 	; Store the byte from BL into the destination string
	inc rcx						; Increment the index counter
	cmp bl, 0					; Check if the byte is the null terminator
	je _return					; If it is, go to the return label
	jne _loop					; Jump back to loop if not null terminator only if je statement is false

_return:
	ret

; Mark stack as non-executable
section .note.GNU-stack
