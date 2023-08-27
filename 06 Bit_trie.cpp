//LEETCODE QUES

// Given an integer array nums
// return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

// Constraints:
// 1 <= nums.length <= 2 * 10^5
// 0 <= nums[i] <= 2^31 - 1



//struct mei use small 's'
struct TrieNode{    //do NOT write struct TrieNode() -> ie. NO bracket
    TrieNode* child[2];

    //i am inserting all nodes int trie, then i am checking for max XOR iteratively
    //so i do NOT require 'bool isEnd'

    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
    }
};   //semicolon is IMP!!

class Solution {
public:
    void insert(int x, TrieNode* root){  //MOST significant bit stores 1st
        for(int i=31; i>=0; i--){  //32 bit integer
            int bit = (x>>i)&1;
            
            if(root->child[bit] == NULL)   //create child if NOT exist
                root->child[bit] = new TrieNode();
            
            root = root->child[bit];
        }
    }
    
    int find_max(int x, TrieNode*root){
        int ret = 0;

        for(int i=31; i>=0; i--){  //MOST significant bit to least significant bit
            int bit = (x>>i)&1;

            if(root->child[1 - bit] != NULL){
                ret = (ret | (1<<i));   //increase ret
                root = root->child[1-bit];
            }else{
                root = root->child[bit];
            }
        }

        return ret;
    }

    int findMaximumXOR(vector<int>& nums) {  //main func
        TrieNode*root = new TrieNode();
        
        for(int i=0; i<nums.size(); i++)    //insert all nodes
            insert(nums[i], root);
        
        int ans = 0;

        for(int i=0;i<nums.size();i++)   //for each node-> find the max XOR in the trie
            ans = max(ans, find_max(nums[i], root));

        return ans;
    }
};
