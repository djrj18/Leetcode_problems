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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * head = NULL;
        TreeNode *prev = NULL;
        TreeNode *curr = root;
        while(curr){
            if(curr->left){
            TreeNode *rgt = curr->left;
            while(rgt and rgt->right){
                rgt = rgt->right;
            }
                TreeNode *lft  = curr->left;
                curr->left = NULL;
                rgt->right = curr;
                curr = lft;
            }
            else{
                if(head == NULL){
                    head = curr;
                    prev = curr;
                }
                else{
                    prev->right = curr;
                    prev = prev->right;
                }
                curr = curr->right;
            }
        }
        return head;
    }
};