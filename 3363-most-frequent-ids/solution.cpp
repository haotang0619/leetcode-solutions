class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<int, long long> mp1;
        map<long long, int> mp2;
        vector<long long> ans;
        for(int i = 0; i < nums.size(); i++) {
            long long cnt1 = mp1[nums[i]];
            mp1[nums[i]] += freq[i];
            long long cnt2 = mp1[nums[i]];
            mp2[cnt1]--;
            mp2[cnt2]++;
            if(mp2[cnt1] <= 0) mp2.erase(cnt1);
            ans.push_back(mp2.rbegin()->first);
        }
        return ans;
    }
};
