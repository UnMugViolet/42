section .text
	global ft_strlen

ft_strlen:
	xor rax, rax          ; Initialize length counter to 0

_loop:
	cmp BYTE [rdi], 0    ; Check if the current byte is the null terminator
	je _return           ; If it is, go to the return label
	inc rax              ; Increment the length counter
	inc rdi              ; Move to the next byte
	jmp _loop            ; Jump back to loop 

_return:
	ret                   ; Return the length in RAX

; Mark stack as non-executable
section .note.GNU-stack
