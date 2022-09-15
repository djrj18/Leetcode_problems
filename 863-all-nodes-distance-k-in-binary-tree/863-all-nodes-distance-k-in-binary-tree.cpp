/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void kDistanceNodesInSubtree(TreeNode * root,int k,vector<int> &nodes){
        if(root == NULL) return;
        if(k == 0) {nodes.push_back(root->val);return;}
        kDistanceNodesInSubtree(root->left,k-1,nodes);
        kDistanceNodesInSubtree(root->right,k-1,nodes);
    }
    void StoreParents(TreeNode*root,map<TreeNode*,pair<TreeNode*,int>> & par){
        if(root == NULL) return;
        if(root->left) par[root->left] = {root,0};
        if(root->right) par[root->right] = {root,1};
        StoreParents(root->left,par);
        StoreParents(root->right,par);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*,pair<TreeNode*,int>> par;
        StoreParents(root,par);
        while(target != root and k){
            kDistanceNodesInSubtree(target,k,ans);
            k--;
            pair<TreeNode*,int>p = par[target];
            if(p.second == 0) p.first->left = NULL;
            else p.first->right = NULL;
            target = p.first;
        }
        kDistanceNodesInSubtree(target,k,ans);
        return ans;
    }
};