class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int prev = -1, cnt = 0;
        for(auto x : nums) {
            if(x != prev) cnt = 1;
            else cnt++;
            if(cnt <= k) ans.push_back(x);
            prev = x;
        }
        return ans;
    }
};
