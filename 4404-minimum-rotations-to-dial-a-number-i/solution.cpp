class Solution {
public:
    int minRotations(string s) {
        int ans = 0, now = 0;
        for(auto& c : s) {
            int d = c - '0', dist = abs(d - now);
            ans += min(dist, 10 - dist);
            now = d;
        }
        return ans;
    }
};
