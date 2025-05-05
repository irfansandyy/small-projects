section .data
    msg1 db "Child Process: ", 0
    msg1_len equ $ - msg1
    msg2 db "Parent Process: ", 0
    msg2_len equ $ - msg2
    newline db 10

section .bss
    buffer resb 21  
section .text
    global _start

_start:
    mov rax, 57
    syscall
    cmp rax, 0
    jg .parent_fork1

    mov rax, 1
    mov rdi, 1
    lea rsi, [rel msg1]
    mov rdx, msg1_len
    syscall

    mov rax, 39
    syscall
    call print_number

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall

.parent_fork1:
    mov rdi, rax
    mov rax, 61
    xor rsi, rsi
    xor rdx, rdx
    syscall

    mov rax, 1
    mov rdi, 1
    lea rsi, [rel msg2]
    mov rdx, msg2_len
    syscall

    mov rax, 39
    syscall
    call print_number

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall

print_number:
    push rbp
    mov rbp, rsp
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push r8
    
    mov r8, rax
    lea rcx, [buffer + 20]
    mov byte [rcx], 0
    
    test r8, r8
    jnz .convert
    
    dec rcx
    mov byte [rcx], '0'
    jmp .output
    
.convert:
    mov rbx, r8 
    test rbx, rbx
    jns .positive
    neg rbx
    
.positive:
    mov rax, rbx
    mov rbx, 10
    
.digit_loop:
    xor rdx, rdx
    div rbx
    
    add dl, '0'
    dec rcx
    mov [rcx], dl
    
    test rax, rax
    jnz .digit_loop
    
    test r8, r8
    jns .output
    
    dec rcx
    mov byte [rcx], '-'
    
.output:
    lea rdx, [buffer + 20]
    sub rdx, rcx
    
    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    syscall

    pop r8
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rbp
    ret