%include "io.inc"

section .text
global CMAIN
CMAIN:
    MOV ECX, [n]        
    MOV EAX, 1          

ciclo:
    CMP ECX, 0
    JE fim

    PRINT_UDEC 4, EAX   
    PRINT_CHAR ' '      

    ADD EAX, 2          
    DEC ECX             
    JMP ciclo

fim:
    NEWLINE
    RET

section .data
n DD 2      
