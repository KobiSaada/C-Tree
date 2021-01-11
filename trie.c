#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "trie.h"


void initNode(TrieNode * pRootTrieNode)
{
    
    TrieNode * pCurNode = pRootTrieNode; 
    char ch;
    
   do{
        ch = getchar();//The C library function int getchar() gets a character (an unsigned char) from stdin. This is equivalent to getc with stdin as its argument.
        ch = tolower(ch);//converts a given letter to lowercase by the The C library function
        if( isStop(ch) )
        {
            if(pCurNode != NULL)
            {
                pCurNode->count++;
            }
            return;
        }
        if (!isCharLeagal(ch)) continue;
        
        if (ChekIfNeedNewWord(ch))
        {
            
            if (pCurNode != pRootTrieNode && NULL != pCurNode )
            {
                pCurNode->count++;
                pCurNode = NULL;
            }
            continue;
        }
        if (NULL == pCurNode)
             pCurNode = pRootTrieNode;
             
        pCurNode = HandleCharacter(pRootTrieNode, pCurNode, ch);
        
   }while( ch != EOF );

   return;
}

void Clean(TrieNode * pRootTrieNode)
{
    
    TrieNode* node = pRootTrieNode;
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
        if(node->children[i] != NULL){
            Clean(node->children[i]);
        }
    }
    free(node);


}
int hasChild(TrieNode * pRootTrieNode){
    
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
       if(pRootTrieNode->children[i] != NULL) return i;
    }
    return NOCHILD;
}

TrieNode * HandleCharacter(TrieNode * pRootTrieNode, TrieNode * pCurNode, char ch)
{
    int index = CHAR_TO_INDEX(ch);
    if (pCurNode->children[index]== NULL) 
    {
        pCurNode->children[index] = newNode();
        pCurNode->children[index]->letter = ch; 
    }
    pCurNode = pCurNode->children[index]; 

    return pCurNode;
}
  
// Returns new trie node (initialized to NULLs) 
TrieNode * newNode(void) 
{ 
    TrieNode * pNode = NULL; 
  
    pNode = (TrieNode *)malloc(sizeof(TrieNode)); 
  
    if (pNode) 
    { 
        pNode->count = 0; 
        for (int i = 0; i < ALPHABET_SIZE; i++){
            pNode->children[i] = NULL; 
        }
    } 
    else{
        printf("Memory Error!");
        return NULL;
    }
    return pNode;
} 

bool isStop(char c){
    return c == EOF;
}

bool ChekIfNeedNewWord(char c){
     if(c == ENTER || c == SPACE || c == TAB) 
        return true;
    return false;              
}

bool isCharLeagal(char c)
{
    bool retVal = true;
    // if((c == ENTER || c == SPACE || c == TAB))
    //     return false;
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ENTER || c == SPACE || c == TAB))
        return retVal;

    return false;
}

void print(TrieNode* head,char word[], int level){
    TrieNode* runner = head;
    
    if(runner == NULL) return;
    if(runner->count > 0){
        word[level] = END;
        printf("%s %ld \n",word,runner->count);
    }
    
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(runner->children[i] != NULL){
            word[level]=runner->children[i]->letter;
            print(runner->children[i], word, level + 1);
        }
    }
}

void printReverse(TrieNode* root,char word[], int level){
    TrieNode * runner = root;
    if(runner == NULL) return;
    if(runner->count > 0){
        word[level] = END;
        printf("%s %ld \n",word,runner->count);
    }
    
    for(int i = ALPHABET_SIZE - 1; i >= 0; i--){
        if(runner->children[i] != NULL){
            word[level] = runner->children[i]->letter;
            printReverse(runner->children[i], word, level + 1);
        }
    }
}

int longestWord(TrieNode * node, int count){
    int ans = count;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(node->children[i] != NULL){
            int x = longestWord(node->children[i], count + 1);
            if(x > ans) ans = x;
        }
    }
    return ans;
}

