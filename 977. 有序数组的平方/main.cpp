class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) pos = i;
            else break;
        }

        vector<int> ans;
        int l = pos, r = pos + 1;
        while(l >= 0 || r < nums.size()){
            if(l >= 0 && r < nums.size()){
                if(-1 * nums[l] > nums[r]){
                    ans.push_back(nums[r] * nums[r]);
                    r++;
                } else{
                    ans.push_back(nums[l] * nums[l]);
                    l--;
                }
            } else if(l >= 0){
                ans.push_back(nums[l] * nums[l]);
                l--;
            } else if(r < nums.size()){
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        return ans;
    }
};
