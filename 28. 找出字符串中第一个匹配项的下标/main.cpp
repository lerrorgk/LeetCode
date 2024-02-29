class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        int ne[m];
        ne[0] = -1;
        for(int i = 1, j = -1; i < m; i++){
            while(j >= 0 && p[i] != p[j + 1])
                j = ne[j];
            if(p[i] == p[j + 1]) j++;
            ne[i] = j;
        }
        for(int i = 0, j = -1; i <= n; i++){
            while(j >= 0 && s[i] != p[j + 1])
                j = ne[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m - 1){
                j = ne[j];
                return i - m + 1;
            }
        }
        return -1;
    }

};
