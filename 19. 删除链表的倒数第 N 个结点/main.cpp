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
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        ListNode* after = dummyHead;
        int idx = 0;
        while(idx <= n) after = after->next, idx++;
        while(after) cur = cur->next, after = after->next;
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        return dummyHead->next;
    }
};
