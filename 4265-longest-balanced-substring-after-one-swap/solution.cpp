// Saw a solution
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> zcnts(n + 1, 0), ocnts(n + 1, 0), diff(n + 1, 0);
        unordered_map<int, vector<int>> mp;
        mp[0] = {0};
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') zcnts[i + 1]++;
            else ocnts[i + 1]++;
            zcnts[i + 1] += zcnts[i], ocnts[i + 1] += ocnts[i];
            diff[i + 1] = zcnts[i + 1] - ocnts[i + 1];
            if(mp[diff[i + 1]].size() < 2) mp[diff[i + 1]].push_back(i + 1);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int d = diff[i];
            // No swap
            for(auto &prev : mp[d]) {
                if(prev < i) ans = max(ans, i - prev);
            }
            // Swap a zero in
            for(auto &prev : mp[d + 2]) {
                if(prev < i && zcnts[i] - zcnts[prev] < zcnts[n]) {
                    ans = max(ans, i - prev);
                    break;
                }
            }
            // Swap an one in
            for(auto &prev : mp[d - 2]) {
                if(prev < i && ocnts[i] - ocnts[prev] < ocnts[n]) {
                    ans = max(ans, i - prev);
                    break;
                }
            }
        }
        return ans;
    }
};
