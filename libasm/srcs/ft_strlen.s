section .text
	global ft_strlen

ft_strlen:
	XOR RAX, RAX          ; Initialize length counter to 0

.loop:
	CMP BYTE [RDI], 0    ; Check if the current byte is the null terminator
	JE .return           ; If it is, go to the return label
	INC RAX              ; Increment the length counter
	INC RDI              ; Move to the next byte
	JMP .loop            ; Jump back to loop 

.return:
	RET                   ; Return the length in RAX

; Mark stack as non-executable
section .note.GNU-stack
