class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> sk;
        for(int i = 0; i < n; i++) {
            int temp = temperatures[i];
            while(!sk.empty() && sk.top().first < temp) {
                auto [t, idx] = sk.top();
                sk.pop();
                ans[idx] = i - idx;
            }
            sk.push({temp, i});
        }
        return ans;
    }
};
