class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), windowSum = 0;
        vector<int> v(n, 0);
        v[0] = 1;
        for(int i = 1; i < n; i++) {
            int now = s[i] - '0', l = i - maxJump, r = i - minJump;
            if(l > 0) windowSum -= v[l - 1];
            if(r >= 0) windowSum += v[r];
            if(now == 0 && windowSum > 0) v[i] = 1;
        }
        return v[n - 1] == 1;
    }
};
