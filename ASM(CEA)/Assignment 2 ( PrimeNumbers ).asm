;By Ank298
;For reference and example purposes only


include "emu8086.inc"

org 100h
start:
print "Enter a number: " ; let the user type the n number in
call scan_num 
mov ax, cx
printn
call print_num


Section1: ; this section is made to process with n =< 2

    cmp ax, 2 ; compare ax - 2
    jl False    ; n is not a prime if ax < 2
    je True    ; n is a prime if ax = 2 
    ja Section2 
; what we doing here is checking n is a prime or not by dividing n for 2 to n-1
; if the result have reamainer so its not a prime otherwise it is.
; down below is a loop to check if n is prime or not


Section2:
    mov z, ax ; because the divisor domain is from 2 to n-1
    dec z     ; so decrease n by 1 to make the maximum value of the divisor (MAX) 
    mov y, ax ; assign n = y
    mov bx, 1 ; assign 1 to bx    


; begin of the loop
Section3:
    mov ax, y ; assign y = n to ax
    mov dx, 0 ; clear dx
    inc bx    ; add divisor by 1, and after each loop it will be added until it reach n-1 
    mov x, bx ; assign divisor value to x
    div x
    cmp dx, 0 ; compare dx - 0
    je False      ; dx is where the remainer is stored if dx = 0 it also mean n is a prime
    jne Section4    ; , otherwise it continue the loop.


Section4:
    mov ax, z ; assign ax = MAX
    cmp bx, ax; compare bx - ax, the divisor with MAX
    je True      ; if the divisor=MAX, the loop end and result in n is a prime number
    jne Section3    ; if not, it return to the beginning of the loop and keep processing until it reach MAX or have a remainer.
 


True: 
print " is a prime."
;printn                             ; delete " ; " to create a multinumber check
;print "Press enter to continue  "
;call scan_num
;mov ax, 0
;call clear_screen
;jmp start      
ret

False:
print " is not a prime."            
;printn                             ; delete " ; " to create a multinumber check
;print "Press enter to continue  "
;call scan_num
;mov ax, 0
;call clear_screen
;jmp start
ret

DEFINE_SCAN_NUM
DEFINE_PRINT_NUM_UNS
DEFINE_PRINT_NUM
DEFINE_CLEAR_SCREEN

z dw 2 ; random var
x dw 1 ; random var
y dw 0 ; random var
ret
