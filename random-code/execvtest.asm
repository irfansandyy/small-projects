section .data
    path1 db '/bin/ls', 0    
    arg1 db '-l', 0
    argv1 dq path1, arg1, 0
    
    path2 db '/bin/echo', 0
    arg2 db 'Hello', 0
    argv2 dq path2, arg2, 0

section .text
    global _start

_start:
    mov rax, 57
    syscall
    cmp rax, 0
    jg .parent_fork1

    mov rax, 59
    lea rdi, [rel path1]
    lea rsi, [rel argv1]
    xor rdx, rdx
    syscall

    mov rax, 60
    mov rdi, 1
    syscall

.parent_fork1:
    mov rdi, rax
    mov rax, 61
    xor rsi, rsi
    xor rdx, rdx
    syscall
    
    mov rax, 57
    syscall
    cmp rax, 0
    jg .parent_fork2

    mov rax, 59
    lea rdi, [rel path2]
    lea rsi, [rel argv2]
    xor rdx, rdx
    syscall

    mov rax, 60
    mov rdi, 1
    syscall

.parent_fork2:
    mov rdi, rax
    mov rax, 61
    xor rsi, rsi
    xor rdx, rdx
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall
