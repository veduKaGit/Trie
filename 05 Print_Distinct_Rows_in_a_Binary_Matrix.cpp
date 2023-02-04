//example below:

// {{1, 0, 0},  
// {1, 1, 1},  
// {1, 0, 0},  
// {0, 1, 0}}; 

//iska o/p = 3




struct Node{
    struct Node *ch[2];
    bool end;
    
    Node(){
        ch[0] = NULL;
        ch[1] = NULL;
        
        end = false;
    }
};


vector<vector<int>> uniqueRow(int m[MAX][MAX],int row,int col)
{
    Node *root = new Node();
    vector<vector<int>> res;
	
    Node *curr;
	
    for(int i=0; i<row; i++){
        curr = root;
        vector<int> tem;
	    
        for(int j=0; j<col; j++){
            tem.push_back(m[i][j]);
		
            if(curr->ch[m[i][j]]==NULL)
                curr->ch[m[i][j]] = new Node();
                
            curr = curr->ch[m[i][j]];
        }
        if(curr->end == false){
            res.push_back(tem);
            curr->end = true;
        }
    }
    
    return res;
}