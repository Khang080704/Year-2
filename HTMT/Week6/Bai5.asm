;Nhap xuat mang 1 chieu n so nguyen.
%include "io.inc"
section .data
    tb db "Mang vua nhap la: ",0
    fmt1 db "%d",0
    fmt2 db "%3d",0
    tb2 db 10,"Cac so chan la: ",0
section .bss
    arr resd 100
    n resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    ;nhap n
    push n
    push fmt1
    call scanf
    add esp,8
    
    ;Khoi tao
    mov ebx, arr ; ebx = dia chi arr
    mov esi,0; i = 0
Nhap.Lap:
    ;nhap a[i]
    push ebx
    push fmt1
    call scanf
    add esp,8
    
    ;Tang dia chi mang
    add ebx,4
    ;Tang i
    inc esi
    ;i < n thi Lap
    cmp esi,[n]
    jl Nhap.Lap
    
    
    ;Xuat tb
    push tb
    call printf
    add esp,4
    
    ;Khoi tao
    mov ebx,arr ; ebx = dia chi arr
    mov esi,0; esi = 0
Xuat.Lap:
    ;xuat a[i]
    push dword[ebx]
    push fmt2
    call printf
    add esp,8
    ;Tang dia chi mang
    add ebx,4
    ;Tang i
    inc esi
    ;i < n thi Lap
    cmp esi,[n]
    jl Xuat.Lap
    
    
    
    xor eax, eax
    ret
    

                  
       