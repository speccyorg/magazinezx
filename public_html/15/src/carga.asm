; Rutina para el volcado de la pantalla de carga
 ORG 40000
  LD HL, 50000     ; Origen: 50000
  LD DE, 16384     ; Destino: la VideoRAM
  LD BC, 6912      ; toda la pantalla
  LDIR             ; copiar
 RET

