class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        int q = 1;
        while(q < nums.size()){
            if(nums[p] != nums[q])
                nums[++p] = nums[q];
            q++;
        }
        return p + 1;
    }
};
