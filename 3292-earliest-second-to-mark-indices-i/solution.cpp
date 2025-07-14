class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        vector<vector<int>> v(n + 1, vector<int>({}));
        for(int i = 0; i < m; i++) v[changeIndices[i]].push_back(i + 1);
        
        int ans = -1;
        while(true) {
            vector<pair<int, int>> indices;
            for(int i = 1; i <= n; i++) {
                if(v[i].size() == 0) return ans;
                indices.push_back({v[i].back(), i});
            }
            sort(indices.begin(), indices.end());
            int cnt = 0;
            for(auto x : indices) {
                auto [idx, i] = x;
                cnt += nums[i - 1];
                if(cnt >= idx) return ans;
                cnt += 1;
            }
            ans = indices.back().first;
            v[indices.back().second].pop_back();
        }
    }
};
