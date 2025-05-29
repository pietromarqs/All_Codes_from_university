%include "io.inc"

section .text
global CMAIN
CMAIN:
    MOV EAX, [num]    
    CMP EAX, 2
    JL nao_primo       

    MOV EBX, 2          

ciclo_teste:
    CMP EBX, EAX        
    JGE sim_primo

    MOV EDX, 0          
    MOV EAX, [num]      
    DIV EBX             
    CMP EDX, 0
    JE nao_primo        

    INC EBX             
    JMP ciclo_teste     

sim_primo:
    PRINT_CHAR 'S'
    PRINT_CHAR 'i'
    PRINT_CHAR 'm'
    NEWLINE
    RET

nao_primo:
    PRINT_CHAR 'N'
    PRINT_CHAR 'a'
    PRINT_CHAR 'o'
    NEWLINE
    RET

section .data
num DD 6
