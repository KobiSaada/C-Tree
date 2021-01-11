CC = gcc
FLAGS = -Wall -g

all: frequency

frequency: mainTree.o trie.o
	$(CC) $(FLAGS) -o frequency mainTree.o trie.o

mainTree.o: mainTree.c trie.h
	$(CC) $(FLAGS) -c mainTree.c 

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c 

.PHONY: clean all

clean:
	rm -f *.o frequency
