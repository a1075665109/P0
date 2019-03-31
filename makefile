all: P0

clean:
	-rm main.o P0 tree.o *.inorder *.preorder *.postorder
P0: main.o tree.o
	g++ -o P0 main.o tree.o
main.o: main.cpp
	g++ -c main.cpp
tree.o:tree.cpp
	g++ -c tree.cpp
