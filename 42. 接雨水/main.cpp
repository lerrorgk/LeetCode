class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftH(height.size());
        vector<int> rightH(height.size());
        leftH[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            leftH[i] = max(leftH[i - 1], height[i]);
        }
        rightH[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i > 0; i--){
            rightH[i] = max(rightH[i + 1], height[i]);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            int h = min(leftH[i], rightH[i]) - height[i];
            if(h > 0) ans += h;
        }
        return ans;
    }
};
