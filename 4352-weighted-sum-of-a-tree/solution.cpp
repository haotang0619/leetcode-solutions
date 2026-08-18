class Solution {
public:
    void traverse(vector<vector<int>>& e, vector<int>& depths, int& h, int u, int d) {
        depths[u] = d;
        h = max(h, d);
        for(auto& v : e[u]) traverse(e, depths, h, v, d + 1);
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> e(n);
        for(int i = 0; i < n; i++) {
            int p = parent[i];
            if(p > -1) e[p].push_back(i);
        }
        vector<int> depths(n);
        int h = 0;
        traverse(e, depths, h, 0, 1);
        long long ans = 0;
        for(int i = 0; i < n; i++) ans += (long long)nums[i] * (h - depths[i] + 1);
        return ans;
    }
};
