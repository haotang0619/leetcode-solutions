class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int cnt = 0;
        for(auto x : s) {
            if(x == '0') ans += cnt;
            else cnt++;
        }
        return ans;
    }
};
