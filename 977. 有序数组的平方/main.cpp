class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int l = 0, r = nums.size() - 1, i = nums.size() - 1;
        while(l <= r){
            if(nums[l] * nums[l] > nums[r] * nums[r]){
                ans[i--] = nums[l] * nums[l];
                l++;
            } else{
                ans[i--] = nums[r] * nums[r];
                r--;
            }
        }
        return ans;
    }
};
