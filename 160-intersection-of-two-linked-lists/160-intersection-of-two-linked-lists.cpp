/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * n1 = headA;
        ListNode * n2 = headB;
        while(n1 || n2){
             if(n1 == NULL){
                n1 = headB;
            }
            if(n2 == NULL){
                n2 = headA;
            }
            if(n1 == n2){return n1;}
            n1 = n1->next;
            n2 = n2->next;    
        }
        return NULL;
    }
};