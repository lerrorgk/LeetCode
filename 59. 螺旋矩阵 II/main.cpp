class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int count = 1;
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j <= n - 2 - 2 * i; j++) res[i][i + j] = count++;
            for(int j = 0; j <= n - 2 - 2 * i; j++) res[i + j][n - 1 - i] = count++;
            for(int j = 0; j <= n - 2 - 2 * i; j++) res[n - 1 - i][n - 1 - i - j] = count++;
            for(int j = 0; j <= n - 2 - 2 * i; j++) res[n - 1 - i - j][i] = count++;
        }
        if(n % 2 == 1) res[(n + 1) / 2 - 1][(n + 1) / 2 - 1] = n * n;
        return res;
    }
};
