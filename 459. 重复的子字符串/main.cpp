class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 0) return false;
        int ne[n];
        ne[0] = -1;
        for(int i = 1, j = -1; i < n; i++){
            while(j >= 0 && s[i] != s[j + 1])
                j = ne[j];
            if(s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        if (ne[n - 1] != -1 && n % (n - (ne[n - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};
