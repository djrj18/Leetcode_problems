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
  
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            int s = q.size();
            map<int,vector<int>> vis;
            for(int i = 0 ;i < s ;i++){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                vis[p.second].push_back(p.first->val);
                if(p.first->left){
                    q.push({p.first->left,p.second-1});
                }  
                if(p.first->right){
                    q.push({p.first->right,p.second+1});
                }
            }
            
            for(auto dt : vis){
                sort(dt.second.begin(),dt.second.end());
                for(auto d : dt.second){
                    mp[dt.first].push_back(d);
                }
            }
            
        }
        vector<vector<int>> ans;
        for(auto data : mp){
           ans.push_back(data.second);
        }
        return ans;
    }
};