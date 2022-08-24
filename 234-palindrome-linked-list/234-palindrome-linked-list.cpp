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
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return true;
        }
        ListNode * fast = head;
        ListNode *curr = head;
        ListNode * prev = NULL;
        while(fast and fast->next){
            fast = fast->next->next;
            ListNode * t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        if(fast){
            curr = curr->next;
        }
        
        while(prev != NULL and curr!=NULL){
            if(prev->val != curr->val){
                return false;
            }
            
            prev = prev->next;
            curr = curr->next;
        }
        
        return true;
    }
};