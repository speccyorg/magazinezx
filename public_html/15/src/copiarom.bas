10 REM Copiamos la ROM en la VideoRAM
20 FOR I=0 TO 6144 : POKE (16384+I), (PEEK I) : NEXT I
30 PAUSE 0
