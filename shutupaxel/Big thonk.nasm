    ;; Testing ideas and replacements for legacy codebases (scriptability, parent derivatives, etc) 
    ;; Intel implemented a shadow stack. we can't ret abuse or jmp without returning anymore. 
    PUSHF
    PUSH 0                     ; RETURN ADDRESS, UNALIGNED, RESERVED MEM ((RAX))
    PUSH RBP                   ; Store RBP before assigned RBP = stack align delta

    MOV RBP, RSP
    AND RSP, 0FFFFFFFFFFFFFFF7h
    SUB RBP, RSP

    SUB RSP, [16 * 8]
    
    MOV QWORD PTR [RSP], RAX   
    
    LEA RAX, [RSP + 128 + RBP]    ; RAX = RBP address (popped later)
    MOV QWORD PTR [RSP + 8], RAX
    ADD RAX, ((sizeof(WORD) * 2))     ; RAX = &flags
    
    ((if (R15) emit:))
    MOV QWORD PTR [RSP + 16], R15
    ((...))
    
    ;; XMM STUFF HERE
    
    MOV RCX, RSP           ; RDI on SysV platforms
    MOV RDX, RAX           ; RSI on SysV platforms
    MOVABS R8, ((context)) ; RDX on SysV platforms
    MOV RAX, ((handler))
    
    ((if WIN))
    -> SUB RSP, 32
    CALL RAX
    ((if WIN))
    -> SUB ADD, 32

    ;; XMM STUFF HERE
 
    LEA RDX, [RSP + 128 + RBP]     ; RDX = RBP address (popped later)
    MOV [RDX], QWORD PTR [RSP + 8] ; *RDX = MachineState_s.rbp
    
    ;; USED IN SECOND BRANCH
    ADD RDX, ((sizeof(WORD)))      ; RDX = &reserved
    MOV [RDX], RAX                 ; *RDX = RAX 
    AND [RDX], 144115188075855870  ; *RDX &= 2 ^ 57
    
    ((if (R15) emit:))
    MOV R15, QWORD PTR [RSP + 16]
    ((...))
    
    CMP RAX, ((calc: 1 << 57 - Intels level 5 upper limit constraint))
    JGE jmpHandler

    nrmlHandler:
        MOV RAX, MOV QWORD PTR [RSP]
        ADD RSP, RBP 
        POP RBP        
        ADD RSP, sizeof((WORD))
        POPF
        RET ((count))
        
    jmpHandler:
        MOV RAX, MOV QWORD PTR [RSP]
        ADD RSP, RBP 
        POP RBP    
        ADD RSP, sizeof((WORD))
        POPF
        JMP [RSP - (sizeof(WORD) * 2)] ; is this bad?. at least nt 4+/linux will not TSS and nuke our flags