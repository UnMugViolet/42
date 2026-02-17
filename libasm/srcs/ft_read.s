section .text
	global ft_read
	extern __errno_location

; ft_read: (rdi = av[0], rsi = av[1], rdx = av[2])

ft_read:
    mov rax, 0							; System call number for sys_read
    syscall								; Make the system call
    cmp rax, 0							; Check if return value is negative
    jl _error							; If negative, handle error
    ret									; Return number of bytes read

_error:
    neg rax								; Make error code positive
    push rax							; Save the error code (rsp % 16 == 0)				
	call __errno_location  wrt ..plt	; Get pointer to errno (rsp % 16 == 8 after push) 	
    pop rdx								; Restore the error code into rdx (rsp % 16 == 0 after pop)
	mov rax, rdx						; Move error code into rax for negation
    mov [rax], edx						; Store errno
    mov rax, -1							; Return -1 in case of error
	ret

; Mark stack as non-executable
section .note.GNU-stack
