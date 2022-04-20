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
class BSTIterator {
public:
    TreeNode *header = NULL;
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        while(curr){
            TreeNode *lft = curr->left;
            if(lft){
                TreeNode *rgt = lft;
                while(rgt->right){
                    rgt = rgt->right;
                }
                rgt->right = curr;
                curr->left = NULL;
                curr = lft;
            }
            else{
                if(header == NULL){
                    header = curr;
                    prev = header;
                }
                else{
                    prev->right = curr;
                    prev = curr;
                }
                curr = curr->right;
            }
        }
    }
    
    int next() {
        int v = header->val;
        header = header->right;
        return v;
    }
    
    bool hasNext() {
        return header != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */