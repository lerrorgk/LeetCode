class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums, target), right_bound(nums, target)};
    }

private:
    int left_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        if (left < 0 || left >= nums.size()) {
            return -1;
        }
        return nums[left] == target ? left : -1;
    }


    int right_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        if (left - 1 < 0 || left - 1 >= nums.size()) {
            return -1;
        }
        return nums[left - 1] == target ? (left - 1) : -1;
    }
};
