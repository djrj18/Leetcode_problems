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
    void getGraph(TreeNode*& root, map<int, vector<int>> &mp){
        if(root == NULL) return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            getGraph(root->left, mp);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            getGraph(root->right, mp);
        }

        return;
    }
    int amountOfTime(TreeNode* root, int start) {

        map<int,vector<int>> mp;

        getGraph(root, mp);
        map<int, bool> visited;
        queue<pair<int,int>> q;
        q.push({start,0});
        visited[start] = true;
         int ans = 0;

         while(q.size()){
             pair<int,int> rt = q.front();
             q.pop();

             ans = max(ans, rt.second);

             for(auto nbr : mp[rt.first]){
                 if(visited[nbr] == false){
                     visited[nbr] = true;
                     q.push({nbr, rt.second + 1});
                 }
             }
         }

         return ans;


        
    }
};