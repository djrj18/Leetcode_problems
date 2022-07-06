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
    pair<int,int> DiaMeter(TreeNode *&root){
        if(!root){
            return {-1,0};
        }
        pair<int,int> left = DiaMeter(root->left);
        pair<int,int> right = DiaMeter(root->right);
        int incRoot = max(left.first,right.first)+1;
        int OverAll = max({left.second,right.second,left.first+right.first+2});
        return {incRoot,OverAll};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return DiaMeter(root).second;
    }
};