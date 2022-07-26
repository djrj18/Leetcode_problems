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
    TreeNode* lcaf(TreeNode* root, int s, int d){
        if(root==NULL)
            return NULL;
        
        if(root->val== s or root->val==d)
            return root;
        
        TreeNode* left= lcaf(root->left, s, d);
        TreeNode* right= lcaf(root->right, s, d);
        
        if(left and right)
            return root;
        return left==NULL ? right:left;
    }
    
    int funsrc(TreeNode* lca, int node, int cnt){
        if(lca==NULL)
            return 0;
        if(lca->val == node)
            return cnt;
        
        int left= funsrc(lca->left, node, cnt+1);
        int right= funsrc(lca->right, node, cnt+1);
        return max(left, right);
    }
    
    bool fundest(TreeNode* lca, int node, string &path){
        if(lca==NULL)
            return false;
        
        if(lca->val==node)
            return true;
        
        bool left= fundest(lca->left, node, path);
        if(left)
            path.push_back('L');
        bool right= fundest(lca->right, node, path);
        if(right)
            path.push_back('R');
        
        return left or right;
    }
    
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* lca= lcaf(root,s,d);
        int ups= funsrc(lca, s, 0);
        string path="";
        fundest(lca, d, path);
        reverse(path.begin(), path.end());
        string ans="";
        while(ups--)
            ans.push_back('U');
        ans+= path;
        return ans;
    }
};
