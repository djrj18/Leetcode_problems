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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        while(1){
            ListNode *tp = st.top();
            st.pop();
            if(tp == curr){
                curr->next = NULL;
                break;
            }else if(curr->next == tp){
                tp->next = NULL;
                break;
            }
            tp->next = curr->next;
            curr->next = tp;
            curr = tp->next;
        }
    }
};