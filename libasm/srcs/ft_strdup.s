section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

; ft_strdup: (rdi = av[0] = string to duplicate)

ft_strdup:
    test rdi, rdi					; Check if input string is NULL
	je _error						; If NULL, handle error

	call ft_strlen					; Get the length of the input string stored in rax
	push rdi						; Save the original string pointer (rsp % 16 == 8)
	inc rax							; Increment length for null terminator
	mov rdi, rax					; Set rdi to the size needed for malloc
	call malloc	wrt ..plt			; Allocate memory for the duplicate string
	test rax, rax					; Check if malloc returned NULL
	je _error_pop					; If NULL, handle error and clean stack

    mov rdi, rax					; Set destination for ft_strcpy
    pop rsi							; Restore original string as source
    push rax						; Save allocated pointer
    call ft_strcpy wrt ..plt		; Copy the string
    pop rax							; Restore allocated pointer as return value
    ret								; Return pointer to duplicated string

_error_pop:
    pop rdi							; Clean up stack (remove saved string pointer)
	jmp _error						; Jump to error handling
_error:
    xor rax, rax					; Return NULL
    ret

return:
	ret

; Mark stack as non-executable
section .note.GNU-stack
