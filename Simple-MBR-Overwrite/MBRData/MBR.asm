[BITS 16]
[ORG 7C00h]

xor     ax, ax     ; DS=0
mov     ds, ax
cld                ; DF=0 because our LODSB requires it
mov     ax, 0012h  ; Select 640x480 16-color graphics video mode
int     10h
mov     si, string
mov     bl, 4      ; Color
call    printstr
jmp     $

printstr:
    mov     bh, 0     ; DisplayPage
print:
    lodsb
    cmp     al, 0
    je      $
    mov     ah, 0Eh   ; BIOS.Teletype
    int     10h

    mov cx, 0x0001
    mov dx, 0x86a0
    mov ah, 0x86
    int 0x15
                    
    jmp     print

string db "Your system has been destroyed!", 0

times 510 - ($-$$) db 0
dw      0AA55h