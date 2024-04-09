section .data
    hello db 'Hello, Holberton', 10 ; The string to print, followed by a newline (10 is ASCII for newline)
    hello_len equ $ - hello         ; Calculate the length of the string

section .text
    global _start

_start:
    ; Write syscall (syscall number 1)
    mov rax, 1             ; syscall number 1 (write)
    mov rdi, 1             ; file descriptor 1 (stdout)
    lea rsi, [hello]       ; pointer to the message
    mov rdx, hello_len     ; length of the message
    syscall

    ; Exit syscall (syscall number 60)
    mov rax, 60            ; syscall number 60 (exit)
    xor rdi, rdi           ; exit code 0
    syscall

