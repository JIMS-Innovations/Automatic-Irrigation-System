
; @file main.asm
; @author Jesutofunmi Kupoluyi (jimsufficiency@gmail.com)
; @brief Skeleton code for Automatic Irrigation System in AVR assembly.
; @version 0.1
; @date 2023-09-25
; @copyright Copyright (c) 2023


; Including required definition files
.include "m32def.inc"

; ATmega328_test2.asm
.org 0x0000
ldi r16,0b00001111 ; Make the lower 4 bits output
out ddrd,r16 ; for port b.
top:
sbi portd, PD7 ; Set bit 0 immediate of port b
rcall delay_5ms ; Calling a subroutine.
cbi portd, PD7; Clear bit 0 immediate of port b
rcall delay_5ms
rjmp top ; Relative jump to label top

;delays_1mhz.asm
; ——————————————————————————
delay_5ms:
rcall delay_1ms
rcall delay_1ms
rcall delay_1ms
rcall delay_1ms
rcall delay_1ms
ret
; ——————————————————————————
; ——————————————————————————
delay_1ms:
push r16 ;save the value in r16
ldi r16,99 ;accounts for overhead of 12 cycles.
delay_1ms1: ; 10 us/loop
nop ; [1 cycle ]
nop
nop
nop
nop
nop
nop
dec r16
brne delay_1ms1 ; [2 cycles ]
pop r16 ;restore the value in r16
ret
; —————————————————————————————————————