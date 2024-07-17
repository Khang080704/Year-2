.data 
	str: .asciiz "Hello asm"
.text 
	#xuat str
	li $v0,4
	la $a0,str
	syscall
