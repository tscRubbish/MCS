mcs: mcs.l mcs.y
	bison -d mcs.y
	flex mcs.l
	gcc -o mcs mcs.tab.c lex.yy.c -lfl
