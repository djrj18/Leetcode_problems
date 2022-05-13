/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node *&root){
        if(root == NULL){
            return;
        }
        Node *t = root;
        Node *curr = NULL;
        while(t){
            if(curr){
                if(t->left){
                    curr->next = t->left;
                    curr = t->left;
                    if(t->right){
                        curr->next = t->right;
                        curr = t->right;
                    }
                }
                else if(t->right){
                    curr->next = t->right;
                    curr = t->right;
                }
            }
            else{
                if(t->left){
                    curr = t->left;
                    if(t->right){
                        curr->next = t->right;
                        curr = t->right;
                    }
                }
                else if(t->right){
                    curr = t->right;
                }
            }
            t = t->next;
        }
       
        
        
       
            solve(root->left);
       
            solve(root->right);
        
        
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};