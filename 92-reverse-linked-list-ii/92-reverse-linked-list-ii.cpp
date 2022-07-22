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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * curr = head;
        ListNode * prev = NULL;
        int cnt = 1;
        while(cnt < left){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        ListNode * pr = NULL;
        ListNode * nd = curr;
        while(cnt <= right){
            ListNode * nxt = curr->next;
            curr->next = pr;
            pr = curr;
            curr = nxt;
            cnt++;
        }
        
        if(prev == NULL){
            head = pr;
        }else{
            prev->next = pr;
        }
        
        nd->next = curr;
        
        return head;
        
    }
};