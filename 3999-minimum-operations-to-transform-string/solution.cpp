class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(auto& c : s) ans = max(ans, (26 - (c - 'a')) % 26);
        return ans;
    }
};
