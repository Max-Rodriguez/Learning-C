; ====== HelloWorld.asm =====
;   First Assembly Program
;
;   Author: Max Rodriguez
;     Date: Feb-02-2021
; ===========================


; Its needed to interact a bit with
; the kernel of the Operating System.
;
; To do this, syscalls are used.

global _start

; ==== Instruction Set ====
section .text:

	_start:
		mov		eax, 0x4			; Set Write syscall
		mov		ebx, 1				; Use stdout as file descriptor
		mov 	ecx, message		; Use message as buffer
		mov 	edx, msg_length		; Use message length variable
		int 	0x80 				; Fire the syscall

		mov 	eax, 0x1 	; Set Exit syscall
		mov 	ebx, 0 		; Exit code to return
		int 	0x80 		; Fire the syscall

; ==== Program Variables ====
section .data:

	; 0xA hex represents a new line char
	message: db "Hello World!", 0xA
	msg_length equ $-message ; Msg Length