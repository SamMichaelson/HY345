all:
	flex --outfile=al.c al.l
	bison -v --yacc --defines --output=parser.c parser.y
	gcc -g -o calc al.c parser.c quad_list.h VMachine.h -I.

clean:
	rm -rf *.out
 