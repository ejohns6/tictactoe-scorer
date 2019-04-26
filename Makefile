compile:
	g++ -Wall Driver.cpp TicTacNode.cpp TicTacNode.h TicTacToe.cpp TicTacToe.h TicTacTrie.cpp TicTacTrie.h  -o OutPut
run:
	./OutPut $(FILE)
val:
	valgrind ./OutPut $(FILE)
clean:
	rm -rf *o
	rm -f *.o
	rm -f *~.gch *#[