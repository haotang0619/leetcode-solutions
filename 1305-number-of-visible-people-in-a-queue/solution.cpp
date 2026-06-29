class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> sk;
        for(int i = 0; i < heights.size(); i++) {
            while(!sk.empty() && sk.top().first <= heights[i]) {
                ans[sk.top().second]++;
                sk.pop();
            }
            if(!sk.empty()) ans[sk.top().second]++;
            sk.push({heights[i], i});
        }
        return ans;
    }
};
