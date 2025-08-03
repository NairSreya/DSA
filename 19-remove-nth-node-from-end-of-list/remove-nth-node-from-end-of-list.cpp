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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while(curr){
            curr = curr->next;
            count++;
        }
        int k = count - n+1;
        
        if(k == 1){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        curr = head;
        for(int i=1; i<k-1; i++){
            curr=curr->next;
        }
        if(curr->next != nullptr) {
            ListNode* nodeToDelete = curr->next;
            curr->next = nodeToDelete->next; 
            delete nodeToDelete;
        }
        

        return head;              
    }
};