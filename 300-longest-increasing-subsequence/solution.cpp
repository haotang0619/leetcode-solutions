class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> e(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) e[i].push_back(j);
            }
        }
        vector<int> rec(n, 1);
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(rec[i] != 1) continue;
            queue<pair<int, int>> qu;
            qu.push({i, 1});
            while(!qu.empty()) {
                auto [u, d] = qu.front();
                qu.pop();
                if(rec[u] > d) continue;
                ans = max(ans, d);
                for(auto &v : e[u]) {
                    if(rec[v] < d + 1) {
                        rec[v] = d + 1;
                        qu.push({v, d + 1});
                    }
                }
            }
        }
        return ans;
    }
};
