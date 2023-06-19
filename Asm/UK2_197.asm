; Muhamad Fadhli Akbar(2200018197)
; UK2 ARSIKOM
section .data
    A dd 5
    B dd 10
    C dd 15
    D dd 2
    E dd 3

section .text
global _start

_start:
    mov eax, dword [A]
    mul dword [B]

    add eax, dword [C]

    mov ebx, dword [D]
    mul dword [E]

    div ebx

    ; Simpan hasil ke dalam register Y
    mov dword [Y], eax

    ; Keluar dari program
    mov eax, 1
    xor ebx, ebx
    int 0x80
