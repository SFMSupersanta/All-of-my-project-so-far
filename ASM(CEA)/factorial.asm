; A program to factorialize a number using recursion using 8086 Assembly Language
include "emu8086.inc"   ; Include emu8086.inc file
org 100h            ; Set the starting address of the program
Start:            ; Start of the program
print "=================================="  ; Print the title
printn                                          ; Print a new line
print "[       prime factorization      ]"  ; Print the title
printn                                ; Print a new line
print "=================================="  ; Print the title
printn                              ; Print a new line
print "Please input a number to facorization:"  ; Print the title
printn                            ; Print a new line
print "n = "                    ; Print the title
call scan_num           ; scan the user input
mov ax, cx              ; move the user input to ax
cmp ax, 2               ; compare ax with 2
jl  returnFalse         ; if ax < 2, jump to returnFalse
printn                  ; print a new line 
call print_num          ; print the user input
printn                  ; print a new line
print " = "             ; print " = "

Looping:                ; loop to factorize the number
mov dx, 0               ; move 0 to dx 
div counter             ; divide ax by counter
cmp dx, 0               ; compare dx with 0
je  IsDevisable         ; if dx = 0, jump to IsDevisable
inc counter             ; increment counter
mov ax, tmp             ; move tmp to ax
jmp Looping             ; jump to Looping

IsDevisable:            ; if the number is devisable by counter
cmp ax, 2               ; compare ax with 2
jl Last                 ; if ax < 2, jump to Last
mov tmp, ax             ; move ax to tmp
mov ax, counter         ; move counter to ax
call print_num          ; print counter
print " * "             ; print " * "
mov ax, tmp             ; move tmp to ax
jmp Looping             ; jump to Looping
    
Last:                   ; if the number is prime
mov ax, counter         ; move counter to ax
call print_num          ; print counter
jmp Return              ; jump to Return


DEFINE_SCAN_NUM         ; define a macro to scan the user input
DEFINE_PRINT_NUM_UNS    ; define a macro to print the user input
DEFINE_PRINT_NUM        ; define a macro to print the user input

counter dw 2            ; counter for the loop 
tmp dw 0                ; temporary variable

returnFalse:            ; if the user input is less than 2
print "The number cannot be factorized" ; print the message

Return:                 ; return to the main program
ret                     
