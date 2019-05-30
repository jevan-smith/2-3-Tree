.SUFFIXES: .o .cpp .x

CFLAGS = -ggdb -std=c++17
objects =  ttTree.o bst.o main.o

main.out: $(objects)
	g++ $(CFLAGS) -o main.out $(objects)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

ttTree.o: ttTree.cpp ttTree.h
bst.o: bst.cpp bst.h
main.o: main.cpp bst.h ttTree.h

clean:
	rm -fr *.o *~ *.x
