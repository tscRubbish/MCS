mcs: mcs.l mcs.y
	bison -d mcs.y
	flex mcs.l
	g++ -g -fsanitize=address -o mcs mcs.tab.c lex.yy.c -lfl
