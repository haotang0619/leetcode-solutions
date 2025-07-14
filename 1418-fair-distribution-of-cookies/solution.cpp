class Solution {
public:
    void solve(vector<int>& cookies, vector<vector<int>>& dist, int idx, int &ans) {
        int max_total = 0;
        for(auto x : dist) max_total = max(max_total, accumulate(x.begin(), x.end(), 0));
        if(max_total >= ans) return;
        if(idx == cookies.size()) {
            ans = min(ans, max_total);
            return;
        }

        for(int i = 0; i < dist.size(); i++) {
            dist[i].push_back(cookies[idx]);
            solve(cookies, dist, idx + 1, ans);
            dist[i].pop_back();
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<vector<int>> dist(k, vector<int>({}));
        sort(cookies.begin(), cookies.end(), greater<int>());
        int ans = INT_MAX;
        solve(cookies, dist, 0, ans);
        return ans;
    }
};
