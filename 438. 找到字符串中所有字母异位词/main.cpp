class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> ans;
        int map[26] = {0};
        int differ = 0;
        int l = 0;
        int r = p.size();
        for(int i = l; i < r; i++){
            map[p[i] - 'a']--;
            map[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(map[i] != 0) differ++;
        }
        if(differ == 0) ans.push_back(0);
        for(;r < s.size(); l++, r++){
            if(map[s[l] - 'a'] == 1){
                differ--;
            } else if(map[s[l] - 'a'] == 0){
                differ++;
            }
            map[s[l] - 'a']--;

            if(map[s[r] - 'a'] == -1){
                differ--;
            } else if(map[s[r] - 'a'] == 0){
                differ++;
            }
            map[s[r] - 'a']++;

            if(differ == 0) ans.push_back(l + 1);
        }
        return ans;
    }
};
