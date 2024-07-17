%include "io.inc"
section .data
    tb1 db "%d la so doi xung",0
    tb2 db "%d khong la doi xung",0
    fmt db "%d",0
section .bss
    n resd 1
    kq resd 1
section .text
global CMAIN
CMAIN:
    ;write your code here
    ;nhap n
    push n
    push fmt
    call scanf
    add esp,8
    
    ;goi ham
    push dword [n]
    call _KTDX
    add esp,4
    
    ;Lay gia tri tra ve (eax) luu vao kq
    mov [kq],eax
    
    ;Kiem tra kq
    cmp dword[kq],1
    je LaDX
    ;xuat tb2 
    push dword [n]
    push tb2
    call printf
    add esp,8
    jmp KetThuc
LaDX:
    ;xuat tb1 
    push dword [n]
    push tb1
    call printf
    add esp,8
KetThuc:
    xor eax, eax
    ret
    
global _KTDX
_KTDX:
    push ebp
    mov ebp,esp
    push ecx
    push edx
    push ebx
    
    ;khoi tao
    mov ecx,0 ; dn = 0
    mov eax,[ebp + 8]; eax = n
    mov ebx,10
_KTDX.Lap:
    xor edx,edx ; edx = 0
    div ebx  ; edx = n % 10, eax = n / 10
    push eax; backup n
    push edx
    mov eax,ecx ; eax = dn  
    mul ebx ; eax = dn * 10
    pop edx
    add eax,edx ; dn * 10 + du
    mov ecx,eax; ecx = eax
    pop eax
    ;kiem tra n != 0 thi Lap
    cmp eax,0
    jne _KTDX.Lap
    
    ;kiem tra dn = n LaDX
    cmp ecx,[ebp + 8]
    je _KTDX.ret1
    mov eax,0
    jmp _KTDX.KT
_KTDX.ret1:
    mov eax,1
        
_KTDX.KT:
    pop ebx
    pop edx
    pop ecx
    pop ebp
    ret 