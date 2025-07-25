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
        if (!head || !head->next || !head->next->next) {
            return; 
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr; 
        
        ListNode* prev = nullptr;
        ListNode* curr = secondHalf;
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        secondHalf = prev; 

        ListNode* first = head;
        ListNode* second = secondHalf;
        
        while (second) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            
            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};