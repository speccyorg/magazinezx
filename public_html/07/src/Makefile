all: prueba.tap aventura.tap

prueba.tap: prueba.bin
	bin2tap prueba.bin prueba.tap
prueba.bin: prueba.c
	zcc +zxansi -vn -o prueba.bin prueba.c -lndos
	
aventura.tap: aventura.bin
	bin2tap aventura.bin aventura.tap
aventura.bin: aventura.c
	zcc +zxansi -vn -o aventura.bin aventura.c -lndos
