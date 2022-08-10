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
    TreeNode *Helper(vector<int>&nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int m = start+(end - start)/2;
        TreeNode * root = new TreeNode(nums[m]);
        root->left = Helper(nums,start,m-1);
        root->right = Helper(nums,m+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);
    }
};