class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int k) {
        vector<int> v;
        for(auto x : grid) for(auto y : x) v.push_back(y);
        sort(v.begin(), v.end());
        int target = v[v.size() / 2];
        int ans = 0;
        for(auto x : v) {
            if(abs(x - target) % k != 0) return -1;
            ans += abs(x - target) / k;
        }
        return ans;
    }
};
