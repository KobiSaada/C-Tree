#define NUM_LETTERS ((int)26)
#define ASCII 97
#define ENTER (char) '\n'   
#define TAB (char) '\t'     
#define SPACE (char) ' '    
#define END (char) '\0'     

#define ALPHABET_SIZE (26) 
  
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

#define NOCHILD -1

// trie node 
typedef struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 

    char letter;
    long unsigned int count;
  
}TrieNode; 

TrieNode *newNode(void);

void getWord();
bool isStop(char c);
bool ChekIfNeedNewWord(char c);
bool isCharLeagal(char c);
void initNode(TrieNode * pRootTrieNode); 
void Clean(TrieNode * pRootTrieNode);
int hasChild(TrieNode * pRootTrieNode);
TrieNode * HandleCharacter(TrieNode * pRootTrieNode, TrieNode * pCurNode, char ch);
void print(TrieNode * root, char * str, int level);
void printReverse(TrieNode* root,char word[], int level);
int longestWord(TrieNode * node, int count);


