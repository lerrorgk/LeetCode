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
        int sizeA = 0;
        int sizeB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA) curA = curA->next, sizeA++;
        while(curB) curB = curB->next, sizeB++;
        ListNode* shortL = sizeA < sizeB ? headA : headB;
        ListNode* longL = sizeA >= sizeB ? headA : headB;
        int idx = 0;
        int abs = sizeA >= sizeB ? sizeA - sizeB : sizeB - sizeA;
        while(idx < abs) longL = longL->next, idx++;

        while(shortL && longL){
            if(shortL == longL) break;
            shortL = shortL->next;
            longL = longL->next;
        }
        return shortL;
    }
};
