#include <bits/stdc++.h> 
using namespace std; 

#define ROW 4 
#define COL 3 


class Node
{ 
    public:
    	bool isEndOfCol; 
    	Node *child[2];
    	
        Node(){
            isEndOfCol = false;
            
            child[0] = NULL;
            child[1] = NULL;
        }
}; 



bool insert(Node** root, vector<vector<int>>&M, int row, int col ) 
{ 
	
	if (*root == NULL) 
		*root = new Node(); 

	
	if (col < COL) 
		return insert (&((*root)->child[M[row][col]]), M, row, col + 1); 

	else  
	{ 
		if (!((*root)->isEndOfCol)) 
			return (*root)->isEndOfCol = 1; 
		
		return 0; 
	} 
} 




int  countDis(vector<vector<int>>&M) 
{ 
	Node* root = NULL;  
    int cnt = 0;
	
	for (int i = 0; i < ROW; ++i) 
	    if (insert(&root, M, i, 0)) 
		    cnt++;
		    
	return cnt;
} 

 
int main() 
{ 
	vector<vector<int>>M = {{1, 0, 0},  
                           {1, 1, 1},  
                           {1, 0, 0},  
                           {0, 1, 0}}; 

	cout << countDis(M); 

	return 0; 
} 
