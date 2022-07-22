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
    ListNode* partition(ListNode* head, int x) {
         ListNode * less = NULL;
        ListNode * curr = head;
        ListNode * prev = NULL;
        
        while(curr){
            if(curr->val < x){
                if(less == NULL){
                    if(curr == head){
                        less = head;
                        prev = head;
                        curr = curr->next;
                    }
                    else{
                        prev->next = curr->next;
                        curr->next = head;
                        head = curr;
                        less = head;
                        curr = prev->next;
                    }
                }
                else{
                    if(less->next == curr){
                        less = curr;
                        prev = curr;
                        curr = curr->next;
                    }
                    else{
                        prev->next = curr->next;
                        curr->next = less->next;
                        less->next = curr;
                        less = curr;
                        curr = prev->next;
                    }
                }
            }
            else{
            prev = curr;
            curr = curr->next;
            }
        }
        return head;
    }
};