class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& num : nums) freq[num]++;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(freq[nums[i]] != freq[nums[j]]) return {nums[i], nums[j]};
            }
        }
        return {-1, -1};
    }
};
