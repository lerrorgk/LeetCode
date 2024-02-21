class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        return -1;
    }
};
