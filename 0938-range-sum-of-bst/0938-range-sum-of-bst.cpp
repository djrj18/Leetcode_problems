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
    void Sum(TreeNode *root, int &ans, int &low, int &high){
        if(root == NULL) return;
        if(root->val >= low and root->val <= high){
            ans += root->val;
            Sum(root->right, ans, low, high);
            Sum(root->left, ans, low, high);
        }else if(root->val > high){
            Sum(root->left, ans, low, high);
        }else if(root->val < low){
            Sum(root->right, ans, low, high);
        }
        return;
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        Sum(root, ans, low, high);
        return ans;
    }
};