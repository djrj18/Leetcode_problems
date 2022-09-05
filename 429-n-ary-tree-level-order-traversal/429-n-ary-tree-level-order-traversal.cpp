/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int s = q.size();
            vector<int> v;
            for(int i = 0 ;i < s ;i++){
                Node * t = q.front();
                q.pop();
                v.push_back(t->val);
                for(auto n : t->children){
                    if(n != NULL) q.push(n);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};