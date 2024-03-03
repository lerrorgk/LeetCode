class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); i++){
            map[nums1[i]] = i;
        }
        stack<int> st;
        for(int i = 0; i < nums2.size(); i++){
            if(st.empty() || nums2[i] <= st.top()){
                st.push(nums2[i]);
            } else{
                while(!st.empty() && nums2[i] > st.top()){
                    if(map.count(st.top()) > 0){
                        int idx = map[st.top()];
                        ans[idx] = nums2[i];
                    }
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        return ans;
    }
};