#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include "trie.h"

#define ZERO 0


int main(int argc, char* argv[]){

    TrieNode * pTrieNode = newNode();
    initNode(pTrieNode);
    int longWord = 0;
    longWord = longestWord(pTrieNode, ZERO);
    char * str = (char *)malloc(longWord);

    if(argc == 2 && strcmp(argv[1], "r") == 0){
        printReverse(pTrieNode, str, ZERO);
    }
    else{
        print(pTrieNode, str, ZERO);
    }
    free(str);
    Clean(pTrieNode);

    return 0;
}
