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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            double d = 0.00000000;
            int s = q.size();
            int n = s;
            while(s--){
                TreeNode * t = q.front();
                q.pop();
                d += (t->val)*1.000000000;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            d = d/(double)n;
            ans.push_back(d);
        }
        return ans;
    }
};