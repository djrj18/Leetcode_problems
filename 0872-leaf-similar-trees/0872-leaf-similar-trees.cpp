/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool GetLeaves(TreeNode*& root, vector<int> & leaves, int &ind){
        if(root->left == NULL and root->right == NULL){
            if(ind == leaves.size()) return false;
            else if(leaves[ind] == root->val){
                ind++;
                return true;
            }else{return false;}
        }else {
                int left = 1 ;
                if(root->left) left = GetLeaves(root->left, leaves, ind);
                int right = 1;
                if(root->right) right = GetLeaves(root->right, leaves, ind);
                return (left && right);
            }
        
        
    }
    
    void Func(TreeNode*&root, vector<int> &leaves){
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL){
            leaves.push_back(root->val);
            return;
        }
        Func(root->left, leaves);
        Func(root->right, leaves);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves;
        Func(root1, leaves);
        for(auto num : leaves) cout<<num<<" ";
        int ind = 0;
        return (GetLeaves(root2, leaves, ind) && (ind == leaves.size()));
        
    }
};