class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for(auto& x : nums1) mp1[x]++;
        for(auto& x : nums2) mp1[x]++, mp2[x]++;
        int ans = 0;
        for(auto& [x, cnt] : mp1) {
            if(cnt % 2 == 1) return -1;
            ans += abs(cnt / 2 - mp2[x]);
        }
        return ans / 2;
    }
};
