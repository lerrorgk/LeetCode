class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int u = 0, r = matrix[0].size() - 1, d = matrix.size() - 1, l = 0;
        while(true){
            for(int i = l; i <= r; i++) ans.push_back(matrix[u][i]);
            if(++u > d) break;
            for(int i = u; i <= d; i++) ans.push_back(matrix[i][r]);
            if(--r < l) break;
            for(int i = r; i >= l; i--) ans.push_back(matrix[d][i]);
            if(--d < u) break;
            for(int i = d; i >= u; i--) ans.push_back(matrix[i][l]);
            if(++l > r) break;
        }
        return ans;
    }
};
