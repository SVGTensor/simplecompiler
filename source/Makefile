CC = g++ $(CFLAGS)

# CFLAGS = -g -O0 -U__GNUC_MINOR__ -Wno-unused -Wno-unused-function -Wno-unused-label -Wno-error -w
### CFLAGS = -g -O0 -Wno-unused -Wno-unused-function -Wno-unused-label -Wno-error -w
CFLAGS = -g -O0 -Wno-unused -Wno-unused-function -Wno-unused-label -Wno-error

simpcomp: comp.y scan.l parser.h \
	nt.o tree.o lt.o icode.o interpret.o value.o
	flex -8 scan.l
	bison -o comp.cpp --defines=comp.cpp.h -v comp.y
	$(CC) $(CFLAGS) -o simpcomp comp.cpp lex.yy.c \
	    nt.o tree.o lt.o icode.o value.o interpret.o

nt.o: nt.cpp nt.h value.h
	$(CC) -c nt.cpp

tree.o: tree.cpp tree.h nt.h lextypes.h
	$(CC) -c tree.cpp

value.o: value.cpp value.h nt.h
	$(CC) -c value.cpp

lt.o: lt.cpp lt.h value.h
	$(CC) -c lt.cpp

icode.o: icode.cpp icode.h lt.h nt.h
	$(CC) -c icode.cpp

interpret.o: interpret.cpp interpret.h value.h icode.h lt.h nt.h
	$(CC) -c interpret.cpp

clean:
	rm -f *.tab.c* *.tab.h* *.yy.c* *.output comp.cpp* *.o simpcomp *\~ simpcomp.exe *.obj
