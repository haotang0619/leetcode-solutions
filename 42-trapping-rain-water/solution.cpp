class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> sk; // [height, idx]
        int ans = 0, n = height.size();
        for(int i = 0; i < n; i++) {
            int prev = 0;
            while(!sk.empty() && sk.top().first <= height[i]) {
                auto [h, idx] = sk.top();
                sk.pop();
                ans += (h - prev) * (i - idx - 1);
                prev = h;
            }
            if(!sk.empty()) ans += (height[i] - prev) * (i - sk.top().second - 1);
            sk.push({height[i], i});
        }
        return ans;
    }
};
