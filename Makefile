mcs: mcs.l mcs.y
	bison -d mcs.y
	flex mcs.l
	g++ -o mcs mcs.tab.c lex.yy.c -lfl
