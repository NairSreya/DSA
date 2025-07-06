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
        ListNode* current = &dummy;

        while(List1!=nullptr && List2!=nullptr){
            if(List1->val <=List2->val){
                current->next = List1;
                List1 = List1->next;
            }else{
                current->next = List2;
                List2 = List2->next;
            }
            current = current->next;
        }
        if(List1!=nullptr){
            current->next = List1;
        }else{
            current->next = List2;
        }
        return dummy.next;

        
    }
};