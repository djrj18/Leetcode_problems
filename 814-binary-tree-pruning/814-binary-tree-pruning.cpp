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
    int  solve(TreeNode *&root){
        if(root == NULL) return 0;
        int ans = 0;
        if(root->val == 1) ans++;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l == 0) root->left = NULL;
        if(r == 0) root->right = NULL;
        
        if(l == 0 and r == 0 and ans == 0) root = NULL;
        
        return l+r+ans;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        solve(root);
        return root;
    }
};