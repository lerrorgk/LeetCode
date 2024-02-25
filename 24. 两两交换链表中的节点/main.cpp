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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead  = new ListNode(0, head);
        ListNode* cur = dummyHead;
        ListNode* tmp1 = nullptr;
        ListNode* tmp2 = nullptr;
        while(cur->next && cur->next->next){
            tmp1 = cur->next;
            tmp2 = cur->next->next->next;
            
            cur->next = cur->next->next;
            tmp1->next->next = tmp1;
            tmp1->next = tmp2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};
