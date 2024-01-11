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
    pair<int,int> MaxDiff(TreeNode*&root, int &ans){
        if(root->left == NULL and root->right == NULL){
            return {root->val, root->val};
        }
        
        pair<int,int> left = {0, INT_MAX};
        pair<int,int> right = {0, INT_MAX};
        if(root->left){
            left = MaxDiff(root->left, ans);
        }
        if(root->right){
           right = MaxDiff(root->right, ans);
        }
        
        int Min = min(left.second, right.second);
        int Max = max(left.first, right.first);
        
        ans = max(ans, max(abs(root->val - Min), abs(Max - root->val)));
        
        Min = min(root->val, Min);
        Max = max(root->val, Max);
        
        return {Max, Min};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        MaxDiff(root, ans);
        return ans;
    }
};