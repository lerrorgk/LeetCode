class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = -1;
        int q = 0;
        while(q < nums.size()){
            if(nums[q] != 0){
                nums[++p] = nums[q];
            }
            q++;
        }
        for(int i = p + 1; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};
