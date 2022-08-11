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
    bool Helper(TreeNode * root,long int min,long int max){
        if(root == NULL){
            return true;
        }
        if(root->val >= min and root->val <= max){
            return Helper(root->left,min,(long int)root->val-1) and Helper(root->right,(long int)root->val+1,max);
        }
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return Helper(root,(long int)INT_MIN,(long int)INT_MAX);
    }
};