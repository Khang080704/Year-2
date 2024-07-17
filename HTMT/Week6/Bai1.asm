%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    PRINT_STRING "Nhap so nguyen duong: "
    GET_DEC 4, eax
    cmp eax, 2
    je prime      

    cmp eax, 1    
    jle not_prime

    ; Kiem tra neu so la chan
    mov ecx, eax   ; Luu tru gia tri cua eax vao thanh ghi khac
    mov edx, 0
    mov ebx, 2
    div ebx
    mov eax, ecx   
    cmp edx, 0
    je not_prime

    mov ebx, 3
loop_check_prime:
    cmp ebx, eax
    jge prime     

    mov ecx, eax   
    mov edx, 0
    div ebx
    mov eax, ecx   
    cmp edx, 0
    je not_prime

    add ebx, 2    ; Tang ebx lên 2 don vi de kiem tra so le tiep theo
    jmp loop_check_prime

not_prime:
    PRINT_STRING "Day khong phai la so nguyen to."
    jmp end_program

prime:
    PRINT_STRING "Day la so nguyen to."
    jmp end_program

end_program:
    ret