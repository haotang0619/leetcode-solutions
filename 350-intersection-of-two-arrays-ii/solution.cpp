class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for(auto& x : nums1) mp1[x]++;
        for(auto& x : nums2) mp2[x]++;
        vector<int> ans;
        for(auto& [x, cnt1] : mp1) {
            int cnt2 = mp2[x], cnt = min(cnt1, cnt2);
            for(int i = 0; i < cnt; i++) ans.push_back(x);
        }
        return ans;
    }
};
