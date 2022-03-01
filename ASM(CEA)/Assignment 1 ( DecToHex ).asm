;By Ank298
;For reference and example purposes only
;----------------------------------------

include "emu8086.inc"
org 100h

start
;brifely comments: to convert n to hexa we first divide it by 16 until n=0, and we put the remainers into the Stack, after that we compare it with the hand-coded Hexademical Library to convert and print the result out. 
print "input n = "
call scan_num                 ; let the user put n in
mov ax, cx
mov x, ax                     ; let x = n
printn
print "Convert "
call print_num                 
print " to hexademical : "
mov cx, 0                     ; Clear CX
jmp S1


S0:
mov ax, 0  ; Clear AX
mov ax, x  ; Let ax = the number that need to be divided 


S1:
mov dx, 0  ; Clear DX
div y      ; Divide a by 16
inc cx     ; A counter : this counter count how many time n have been divided so that the program can print out the exact result and prevent it from going infinitely.
push dx    ; Push dx's value into the Stack so later we can print it out in reverse order
mov x, ax  ; let x = the dividend
cmp ax, 0  ; comp ax = 0, if ax=0 so the divide process is over, if not, repeat the process.
jne s0     ; loop the process
je s2      ; move to the next stage



S2:        ; from here we POP out the stack and compare its values sequencely
pop ax
cmp ax, 10
jl onetonine

cmp ax, 10
je ten

cmp ax, 11
je ele

cmp ax, 12
je twe

cmp ax, 13
je thi

cmp ax, 14
je fou

cmp ax, 15
je fif

cmp ax, 16
je six

cmp ax, 17
je sev

 

; down below is the Hexademical Library to compare and convert
; the 'dec cx' line is to decrease the counter each time a character is printed out, and if the counter = 0, the program is finished.
onetonine:
call print_num
dec cx
cmp cx, 0
je End
jmp S2

ten:
Print 'A'
dec cx
cmp cx, 0
je End
jmp S2

ele:
Print 'B'
dec cx
cmp cx, 0
je End
jmp S2

twe:
Print 'C'
dec cx
cmp cx, 0
je End
jmp S2

thi:
Print 'D'
dec cx
cmp cx, 0
je End
jmp S2

fou:
Print 'E'
dec cx
cmp cx, 0
je End
jmp S2 

fif:
Print 'F'
dec cx
cmp cx, 0
je End
jmp S2

six:
Print '10'
dec cx
cmp cx, 0
je End

sev:
Print '11'
dec cx
cmp cx, 0
je End 

End: ; where the process ended
printn
jmp start
ret






DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS

x dw 0
y dw 16


