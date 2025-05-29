%include "io.inc"
section .text
global CMAIN
CMAIN:
    MOV EAX, [num1];
    MOV ECX, EAX;
    MOV EBX, [num2];
    ciclo1:
        IMUL EBX, ECX;
    loop ciclo1;
    PRINT_UDEC 4, EBX

SECTION .DATA
num1 DD 2
num2 DD 1