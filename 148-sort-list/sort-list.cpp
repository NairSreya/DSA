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
    ListNode* sortList(ListNode* head) {
        vector<int> result;
        vector<int> ans;
        ListNode* curr = head;

        if(head == nullptr){
            return nullptr;
        }

        
        while(curr!=nullptr){
            result.push_back(curr->val);
            curr = curr->next;
        }
        sort(result.begin(), result.end());
        ListNode* newHead = new ListNode(result[0]);
        ListNode* temp = newHead;

        for(int i=1; i<result.size(); i++){
            temp->next = new ListNode(result[i]);
            temp = temp->next;
        }
        return newHead;

    }
};