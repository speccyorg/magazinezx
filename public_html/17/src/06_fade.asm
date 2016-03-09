  ; Mal uso de la pila: reset
  ORG 50000

   ld de, 16384
   ld bc, 32*192
   ld hl, 1234
   ldir                        ; copy some data
 
   ld de, 16384+6144
   ld bc, 768
   ld hl, 1234
   ldir                        ; copy some atributes

   ld b, 16

fadescreen_loop1:
   ld hl, 16384+6144
   ld de, 768

fadescreen_loop2:
   ld a, (hl)                  ; get attr

   ld c, a
   and 7                       ; get last  bits
   jr z, fadescreen_ink_zero   ; if its zero, not dec it

   dec a
   ex af, af'

fadescreen_ink_zero:
   ld a, c
   and 7
   sra a
   sra a
   sra a
   jr z, fadescreen_paper_zero   ; if its zero, not dec it

   dec a

fadescreen_paper_zero:
   sla a
   sla a
   sla a
   ld c, a
   ex af, af'
   add a, c


   ld (hl), a
   inc hl

   dec de                       ; internal loop
   ld a, d
   or e
   jp nz, fadescreen_loop2

   push bc
   ld b, 100
wait:                           ; wait loop
   dec bc
   ld a, b
   or c
   jr nz, wait
   pop bc
   djnz fadescreen_loop1

loop:
   jp loop;

   END 50000 
