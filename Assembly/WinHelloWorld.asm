; ===   Hello World - x86 Assembly in Win32   ===
;
; My first Assembly Program for x86 architecture.
; Using Microsoft MASM assembler for compilation.
;
; ===============================================
;
;	Author:		Max Rodriguez
;	Date: 		Feb-26-2021
;
; ===============================================

.386
.model flat, stdcall
option casemap :none

; Included Libraries

include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib

.data	; Program Data

	message db "Hello World!", 0

.code	; Program Instructions

	main:	; Main Block

		invoke StdOut, addr message		; Invoke Standard Out Syscall
		invoke ExitProcess, 0			; Invoke Exit Syscall, exit code 0

	end main