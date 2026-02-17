section .text
	global ft_write				; When called rsp % 16 == 8, make sure to align back when calling other functions (like __errno_location)
	extern __errno_location

; ft_write: (rdi = av[0], rsi = av[1], rdx = av[2])

ft_write:
	mov rdi, rdi						; File descriptor (1 for stdout)
	mov rsi, rsi						; Buffer to write
	mov rdx, rdx						; Number of bytes to write
	mov rax, 1							; System call number for sys_write
	syscall								; Make the system call
	jc _error							; If carry flag is set, an error occurred
	ret

_error:
	push rax							; Save the error code (rsp % 16 == 0)
	call __errno_location  wrt ..plt	; Get pointer to errno 
	mov rdi, rax						; Set rdi to point to errno 
	pop rax								; Restore the error code (rsp % 16 == 8)
	neg eax								; Negate the error (in eax part of rax) to get the positive errno value
	mov [rdi], eax						; Set errno to the error code
	mov rax, -1							; Return -1 on error
	ret

; Mark stack as non-executable
section .note.GNU-stack
