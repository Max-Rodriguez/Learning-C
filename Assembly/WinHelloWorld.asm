;
;     Hello World  -  x86 Assembly in Win32
;
; My first Assembly Program for x86 architecture
; using Microsoft MASM assembler for compilation.
;
; ===============================================
;
;	Author:		Max Rodriguez
;	Date: 		Feb-26-2021
;
; ===============================================


;       ------ Low Level Basics ------
;
;  An Executable process uses 4 main resources.
;
;  Heap  |  Registers  |  Stack  |  Instructions
;
; 	Heap - Manually Allocated Memory by Process
; This is dynamically allocated memory, usually larger.
;
; 	Registers - Pointers / Variables allocated, 8 bytes.
; These are stored in the CPU which is faster than-
; reaching for random access memory at every access.
;
; 	(In x86 architecture, there are 6 general purpose
; registers, eax, ebx, ecx, edx, esi, edi, and 3
; reserved registers, ebp, esp, eip.)
;
; 	Stack - The 'stack' or conveyor belt serving the
; instructions in order from memory.
;
; 	Instructions - The very building block of an
; executable program. These instructions are stored
; in the process stack at execution time.

; ========== Initialization ===========

.386
.model flat, stdcall
option casemap :none

; Included Libraries

include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib

; =========== Main Assembly ===========

.data	; Program Data

	message db "Hello World!", 0

.code	; Program Instructions

	main:	; Main Block

		invoke		StdOut, addr message		; Invoke Standard Out Syscall with 'message'
		invoke 		ExitProcess, 0				; Invoke Exit Syscall, exit code 0

	end main