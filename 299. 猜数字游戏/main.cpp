class Solution {
public:
    string getHint(string secret, string guess) {
        int secretMap[10] = {0}, guessMap[10] = {0};
        int countA = 0, countB = 0;
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i]){
                countA++;
            } else{
                secretMap[secret[i] - '0']++;
                guessMap[guess[i] - '0']++;
            }
        }
        for(int j = 0; j < 10; ++j){
                countB += min(guessMap[j], secretMap[j]);
        }
        return to_string(countA) + "A" + to_string(countB) + "B";;
    }
};
