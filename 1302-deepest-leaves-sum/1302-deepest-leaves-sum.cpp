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
    
    void solve(TreeNode * root,int curr,int &high,map<int,int>&sum){
        if(root == NULL){
            return; 
        }
        if(root->left == NULL and root->right == NULL){
            if(curr > high){
                high = curr;
                sum[high] = root->val;
            }
            else if(curr == high){
                sum[high] += root->val;
            }
            return;
        }
        solve(root->left,curr+1,high,sum);
        solve(root->right,curr+1,high,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int high = -1;
        map<int,int> sum;
        solve(root,0,high,sum);
        return sum[high];
    }
};