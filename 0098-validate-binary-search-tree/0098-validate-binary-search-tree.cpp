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
    bool CheckBST(TreeNode*& root, long int min, long int max){
        if(root == NULL) return true;
        else if(root->val >= min and root->val <= max){
            return CheckBST(root->left, min, 1ll*root->val-1ll) and CheckBST(root->right, 1ll*root->val+1ll, max);
        }
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return CheckBST(root, (long)INT_MIN, (long)INT_MAX);
    }
};