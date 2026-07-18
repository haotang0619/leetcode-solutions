class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size(), score = 0, maxScore = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n - 1;
        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i++], score++, maxScore = score;
            } else {
                if(score == 0) break;
                power += tokens[j--], score--;
            }
        }
        return maxScore;
    }
};
