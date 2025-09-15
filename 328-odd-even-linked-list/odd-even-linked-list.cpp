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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> arr1;
        ListNode* curr = head;
        vector<int> result;

        if(head==nullptr){
            return nullptr;
        }

        while(curr!=nullptr){
            arr1.push_back(curr->val);
            curr = curr->next;
        }
        int n = arr1.size();

        for(int i = 0; i < n; i += 2){
            result.push_back(arr1[i]);
        }

        for(int i = 1; i < n; i += 2){
            result.push_back(arr1[i]);
        }
        
        curr = head;
        for(int k = 0; k < result.size(); k++){
            curr->val = result[k];
            curr = curr->next;
        }
        
        return head;
    }
};