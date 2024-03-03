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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        int size = 0;
        while(cur){
            size++;
            cur = cur->next;
        }
        int moreSize = size % k;
        vector<int> lsize;
        for(int i = 0; i < k; i++){
            if(i < moreSize) lsize.push_back(size / k + 1);
            else lsize.push_back(size / k);
        }
        vector<ListNode*> ans;
        cur = head;
        for(int s : lsize){
            if(s == 0){
                ans.push_back(nullptr);
                continue;
            }
            ans.push_back(cur);
            int idx = 0;
            while(idx < s){
                if(idx == s - 1){
                    ListNode* tmp = cur->next;
                    cur->next = nullptr;
                    cur = tmp;
                }else{
                    cur = cur->next;
                }
                idx++;
            }
        }

        return ans;
    }
};
