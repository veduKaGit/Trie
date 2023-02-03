// Time Complexity:
// Search : Theta(n)
// Insert : O(n)



const int ALPHABET_SIZE = 26; //considering only lowercase english letters
 
//an empty trie is represented as => a (root node) where (all 26 children are NULL) AND (isEndOfWord == false)

struct TrieNode 
{ 
	TrieNode *children[ALPHABET_SIZE]; 
	bool isEndOfWord;  //indicates if this node is end of a word or not
	
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

int main()
{ 
	
	string keys[] = {"bad", "bat", "geeks", "geeks", "cat", "cut"}; 
	
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = new TrieNode(); 

	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 
	
	search(root, "bat")? cout << "Yes\n" : cout << "No\n"; 
	search(root, "gee")? cout << "Yes\n" : cout << "No\n"; 
	
	return 0; 
} 
