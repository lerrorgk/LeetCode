class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int64_t pS = s.size() - 1;
        int64_t pT = t.size() - 1;
        int64_t skipS = 0;
        int64_t skipT = 0;
        while(pS >= 0 || pT >= 0){
            while(pS >= 0){
                if(s[pS] == '#'){
                    skipS++, pS--;
                } else if(skipS > 0){
                    skipS--, pS--;
                } else{
                    break;
                }
            }

            while(pT >= 0){
                if(t[pT] == '#'){
                    skipT++, pT--;
                } else if(skipT > 0){
                    skipT--, pT--;
                } else{
                    break;
                }
            }

            if(pS >= 0 && pT >= 0){
                if(s[pS] != t[pT]) return false;
            } else{
                if(pS >= 0 || pT >= 0) return false;
            }
            pS--, pT--;
        }
        return true;
    }
};
