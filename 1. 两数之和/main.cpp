class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map[target - nums[i]] != 0){
                return {i, map[target - nums[i]] - 1};
            }
            map[nums[i]] = i + 1;
        }
        return {};
    }
};
