include 'emu8086.inc'
org 100h

; add your code here  

print "Enter the width of rectangle: "
call scan_num
printn
mov width, cl
print "Enter the height of rectangle: "
call scan_num
printn
mov height,cl

ret

define_print_string
define_scan_num
define_print_num
define_print_num_uns


aerea db 0
width db 0
height db 0
