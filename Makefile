all: coordinador.c
	gcc coordinador.c -o coordinador
	gcc mapeo.c -o mapeo
	gcc reduce.c -o reduce
	
 
