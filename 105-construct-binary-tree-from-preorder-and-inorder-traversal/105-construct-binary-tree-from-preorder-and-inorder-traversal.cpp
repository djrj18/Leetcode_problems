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
    TreeNode* helper(vector<int> pre,vector<int> ino,int instart,int inend,int &prestart){
        if(instart>inend){
            return NULL;
        }
        int i ;
        for( i = instart;i<=inend;i++){
            if(pre[prestart] == ino[i]){
                break;
            }
        }
        prestart++;
        TreeNode * root = new TreeNode(ino[i]);
        root->left = helper(pre,ino,instart, i-1,prestart);
        root->right = helper(pre,ino,i+1,inend,prestart);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int prestart = 0;
        return helper(preorder,inorder,0,n-1,prestart);
        
    }
};