class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 0; i < nums.size() - k + 1; i++) {
            set<int> st;
            for(int j = i; j < i + k; j++) st.insert(nums[j]);
            for(auto x : st) mp[x]++;
        }
        int ans = -1;
        for(auto &x : mp) ans = x.second == 1 ? x.first : ans;
        return ans;
    }
};
