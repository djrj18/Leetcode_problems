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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode * curr = root;
        vector<int> ans;
        while(true){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            if(st.size() == 0) return ans;
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            if(curr->right) curr = curr->right;
            else curr = NULL;
        }
        
        return ans;
    }
};