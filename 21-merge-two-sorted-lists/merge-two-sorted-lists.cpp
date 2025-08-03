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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
        ListNode dummy(0);
        ListNode* ans = &dummy;
        
        if(List1==NULL &&  List2 == NULL){
            return nullptr;
        }
        else if(List1 != NULL && List2 == NULL){
            return List1;
        }
        else if(List1 == NULL && List2 != NULL){
            return List2;
        }
        
        ListNode* curr = List1;
        ListNode* curr1 = List2;

        while(curr!= nullptr && curr1!=nullptr){
            if(curr->val < curr1->val){
                ans->next = curr;
                curr = curr->next;
            }
            else if(curr->val > curr1->val){
                ans->next = curr1;
                curr1 = curr1->next;
            }
            else if(curr->val == curr1->val){
                ans->next = curr;
                curr = curr->next;
                ans = ans->next;
                ans->next = curr1;
                curr1 = curr1->next;
            }
            ans = ans->next;
        }
        
        // Add remaining elements
        if(curr != nullptr){
            ans->next = curr;
        }
        if(curr1 != nullptr){
            ans->next = curr1;
        }
        
        return dummy.next;
    }
};