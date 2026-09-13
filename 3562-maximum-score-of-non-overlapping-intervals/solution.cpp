class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> v(n);
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            auto& x = intervals[i];
            nums.insert(nums.end(), {x[0], x[1]});
            v[i] = {x[0], x[1], x[2], i};
        }
        
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int sz = 0;
        for(auto& x : nums) {
            if(mp.contains(x)) continue;
            mp[x] = sz++;
        }
        sort(v.begin(), v.end(), [&](auto& a, auto& b) {
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });

        using pllv = pair<long long, vector<int>>;
        vector<vector<pllv>> dp(sz, vector<pllv>(5, {-1, {}}));
        int prev = 0;
        long long maxW = -1;
        vector<int> ans;
        for(auto& x : v) {
            int l = mp[x[0]], r = mp[x[1]], w = x[2], i = x[3];
            while(prev < r) {
                for(int len = 1; len <= 4; len++) dp[prev + 1][len] = dp[prev][len];
                prev++;
            }

            for(int len = 1; len <= 4; len++) {
                auto& [nowW, nowArr] = dp[r][len];
                if(len == 1) {
                    if(w > nowW) dp[r][len] = {w, {i}};
                    else if(w == nowW && nowArr > vector<int>({i})) {
                        dp[r][len] = {w, {i}};
                    }
                } else {
                    if(l == 0) continue;
                    auto& [prevW, prevArr] = dp[l - 1][len - 1];
                    auto arr = prevArr;
                    arr.push_back(i);
                    sort(arr.begin(), arr.end());
                    if(prevW + w > nowW) dp[r][len] = {prevW + w, arr};
                    else if(prevW + w == nowW && nowArr > arr) {
                        dp[r][len] = {prevW + w, arr};
                    }
                }
                
                if(maxW < nowW) maxW = nowW, ans = nowArr;
                else if(maxW == nowW && ans > nowArr) ans = nowArr;
            }
        }
        return ans;
    }
};
