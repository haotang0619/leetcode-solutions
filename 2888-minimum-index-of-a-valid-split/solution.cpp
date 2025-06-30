class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mp;
        int dom = -1, max_cnt = -1, half = nums.size() / 2;
        for(auto x : nums) {
            if(mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;
            if(mp[x] > half) dom = x;
        }
        int dom_cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == dom) dom_cnt++;
            if(dom_cnt > (i + 1) / 2 && mp[dom] - dom_cnt > (nums.size() - 1 - i) / 2) return i;
        }
        return -1;
    }
};
