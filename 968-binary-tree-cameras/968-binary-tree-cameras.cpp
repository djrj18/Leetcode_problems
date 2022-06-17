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
    int ans(TreeNode * root,int &ass){
        if(!root){
            return 0;
        }
        int left = ans(root->left,ass);
        int right = ans(root->right,ass);
        if(left == 1 or right == 1){
            ass++;
            return 2;
        }
        else if(left == 2 or right == 2){
            return 0;
        }
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        int ass = 0;
        if(ans(root,ass) == 1 ) ass++;
        return ass;
    }
};