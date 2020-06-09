STR x30, [sp, #-16]!
STP x0, x1, [sp, #-16]!
STP x2, x3, [sp, #-16]!
STP x4, x5, [sp, #-16]!
STP x6, x7, [sp, #-16]!
STP x8, x9, [sp, #-16]!
STP x10, x11, [sp, #-16]!
STP x12, x13, [sp, #-16]!
STP x14, x14, [sp, #-16]!
STP x16, x15, [sp, #-16]!
 
MOV x1, sp

MOV x0,  #(i16[0])
MOVK x0, #(i16[1]), lsl 16
MOVK x0, #(i16[2]), lsl 32
MOVK x0, #(i16[3]), lsl 48
 
BLR x0
 
LDP x16, x15, [SP], #16
LDP x14, x14, [SP], #16
LDP x12, x13, [SP], #16
LDP x10, x11, [SP], #16
LDP x8, x9, [SP], #16
LDP x6, x7, [SP], #16
LDP x4, x5, [SP], #16
LDP x2, x3, [SP], #16
LDP x0, x1, [SP], #16
 
LDR x30, [sp], #16
 
RET

(check https://github.com/Rprop/And64InlineHook for nice hooking code)