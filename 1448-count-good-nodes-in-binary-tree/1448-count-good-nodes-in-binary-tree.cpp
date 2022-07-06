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
    void ans(TreeNode *&root, int &cnt,int maxTill){
        if(root == NULL){
            return;
        }
        if(maxTill <= root->val){
            cnt++;
        }
        ans(root->left,cnt,max(maxTill,root->val));
        ans(root->right,cnt,max(maxTill,root->val));
        
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxTill = INT_MIN;
        ans(root,cnt,maxTill);
        return cnt;
    }
};