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
    void Left_in(TreeNode *root,TreeNode *&n1,TreeNode*&pre){
        if(root == NULL or n1!= NULL){
            return;
        }
        Left_in(root->left,n1,pre);
        if(pre and (root->val < pre->val)){
            n1 = pre;
            return;
        }
        pre = root;
        Left_in(root->right,n1,pre);
    }
    void Right_in(TreeNode *root,TreeNode* &n2 ,TreeNode *&pre){
        if(root == NULL or n2!= NULL){
            return;
        }
        Right_in(root->right,n2,pre);
        if(pre and (root->val > pre->val)){
            n2 = pre;
            return;
        }
        pre = root;
        Right_in(root->left,n2,pre);
    }
    void recoverTree(TreeNode* root) {
        TreeNode * n1 = NULL;
        TreeNode * n2 = NULL;
        TreeNode *pre = NULL;
        Left_in(root,n1,pre);
        pre = NULL;
        Right_in(root,n2,pre);
        swap(n1->val,n2->val);
    }
};