// basically delete a word from the trie

// there can be 3 cases (to understand, open {02 more_intro.md} wala file)
//   1. delete zoo (delete whole word)
//   2. delete geek (just make isEndOfWord = false for letter k wala node)
//   3. delete bad (just delete a single node)

//writing delete function is simple if we write recursively.





 
#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

 
struct TrieNode 
{ 
	TrieNode *children[ALPHABET_SIZE]; 
	bool isEndOfWord; 
	
	TrieNode(){
	    isEndOfWord = false;
	    for(int i=0; i<ALPHABET_SIZE; i++)
	        children[i] = NULL;
	}
}; 



void insert(struct TrieNode *root, string key) //better use string & key
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 	 //a->0, b->1, c->2...so on...for the children array ka indexing
		
		if (pCrawl->children[index] == NULL) 
			pCrawl->children[index] = new TrieNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	 
	pCrawl->isEndOfWord = true;  //last waale node ka (isEndOfWord = true) kar do
} 



bool search(struct TrieNode *root, string key)   //better use string & key
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a';   	//a->0, b->1, c->2...so on...for the children array ka indexing
		
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); //IMP => 2 conditions
} 



bool isEmpty(TrieNode* root)  //returns true if ALL children are NULL
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
} 



TrieNode* remove(TrieNode* root, string &key, int i)   // i is the current index of key we are on
{ 
    if (root==NULL)     //base-case 1
        return NULL; 
  
    
    if (i == key.size()) {   //base-case 2
        
        if (root->isEndOfWord == true)   //make isEndOfWord for that node = false
            root->isEndOfWord = false; 
  
        if (isEmpty(root)) {    //if node has no children, delete that particular node
            delete (root); 
            root = NULL; 
        } 
  
        return root;
    } 
  
    
    int index = key[i] - 'a'; 
	
    root->children[index] = remove(root->children[index], key, i + 1);  //recursive => root and i change
  
    
    if (isEmpty(root) && root->isEndOfWord == false) {   //if node has (no children) AND (is NOT the end of another word), delete that particular node
        delete (root); 
        root = NULL; 
    } 
  
    return root; 
} 
 

 
int main()
{ 
	string keys[] = {"an", "and", "ant", "bad", "bat", "zoo"};  
	
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = new TrieNode(); 

	
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 

	root = remove(root, "zoo", 0); 
	
	search(root, "zoo")? cout << "zoo --- " << "Yes\n" : cout << "zoo --- " << "No\n"; 
	 
	return 0; 
} 
