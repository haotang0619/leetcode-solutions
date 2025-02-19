class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long> mp;
        long long size = nums.size();
        for(int i = 0; i < size; i++) {
            int val = nums[i] - i;
            if(mp.find(val) == mp.end()) mp[val] = 1;
            else mp[val]++;
        }
        
        long long cnt = 0;
        for (auto& m : mp) {
            if (m.second >= 2) cnt += (m.second * (m.second - 1)) / 2;
        }
        return (size * (size - 1) / 2) - cnt;
    }
};
