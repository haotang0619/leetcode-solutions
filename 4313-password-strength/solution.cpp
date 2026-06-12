class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<int> st;
        int score = 0;
        for(auto c : password) {
            int now = 0;
            if(c >= 'a' && c <= 'z') now = 1;
            else if(c >= 'A' && c <= 'Z') now = 2;
            else if(c >= '0' && c <= '9') now = 3;
            else now = 5;
            if(!st.contains(c)) {
                st.insert(c);
                score += now;
            }
        }
        return score;
    }
};
