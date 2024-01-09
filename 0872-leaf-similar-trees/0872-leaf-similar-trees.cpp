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
    void GetLeaves(TreeNode*& root, vector<int> &leaves){
        if(root->left == NULL and root->right == NULL){
            leaves.push_back(root->val);
            return;
        }
        if(root->left) GetLeaves(root->left, leaves);
        if(root->right) GetLeaves(root->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        GetLeaves(root1, leaves1);
        GetLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
};