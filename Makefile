ALL: init getty

init:	init.c
	gcc init.c -o init

getty: getty.c
	gcc getty.c -o getty
