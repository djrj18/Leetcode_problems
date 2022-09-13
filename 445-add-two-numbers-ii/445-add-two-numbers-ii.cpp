/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1,st2;
        ListNode * h= NULL;
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(st1.size() and st2.size()){
            int d = carry+st1.top()+st2.top();
            st1.pop();
            st2.pop();
            ListNode * t = new ListNode(d%10);
            t->next = h;
            h = t;
            carry = d/10;
        }
        
        while(st1.size()){
            int d = carry+st1.top();
            st1.pop();
            ListNode * t = new ListNode(d%10);
            t->next = h;
            h = t;
            carry = d/10;
        }
        while(st2.size()){
            int d = carry+st2.top();
            st2.pop();
            ListNode * t = new ListNode(d%10);
            t->next = h;
            h = t;
            carry = d/10;
        }
        if(carry){
        ListNode * t = new ListNode(carry);
        t->next = h;
        h = t;
        }
        return h;
    }
};