class Solution {
public:
    void tree_traversal(TreeNode* root , unordered_map<int,int> &freq){
        if( root==NULL )  return;
        freq[root->val]++;
        tree_traversal(root->right , freq);
        tree_traversal(root->left , freq);
    }

    vector<int> findMode(TreeNode* root) {
        //intalize hash map
        unordered_map<int,int> freq;

        //traverse the tree
        tree_traversal(root , freq);

        //find the most frequency 
        int max_freq = 0;
        for( auto it : freq ){
            max_freq = max( max_freq , it.second );
        }

        //find all elemnets with max frequency
        vector<int> most_freq;
        for( auto it : freq ){
            if( it.second == max_freq )
            most_freq.push_back( it.first );
        }
        
        return most_freq;
    }
};