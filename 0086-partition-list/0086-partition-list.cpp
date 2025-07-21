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
        ListNode lessDummy(0), moreDummy(0);
        ListNode *less = &lessDummy, *more = &moreDummy;
        while(head){
            if(head->val <x){
                less->next = head;
                less = less->next;
            } else{
                more->next = head;
                more = more->next;
            }
            head = head->next;
        }
        more->next = nullptr;
        less->next = moreDummy.next;
        return lessDummy.next;
    }
};