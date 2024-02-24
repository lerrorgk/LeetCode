class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[nums.size() - 1] < target){
            return nums.size();
        }
        if(nums[0] > target){
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        while(left + 1 < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] == target){
                return middle;
            }
            if(nums[middle] < target){
                left = middle;
            }
            if(nums[middle] > target){
                right = middle;
            }
        }
        if(nums[left] == target){
            return left;
        }
        if(nums[right] == target){
            return right;
        }
        if(left + 1 > nums.size() - 1 || nums[left + 1] > target){
            return left + 1;
        }
        return -1;
    }
};
