// Saw all hints
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        unordered_map<int, int> mp, freq;
        int n = nums.size(), totalCnt = 0, maxCnt = 0;
        for(int i = 0; i < n; i++) {
            if(++freq[nums[i]] > n || ++freq[forbidden[i]] > n) return -1;
            if(nums[i] == forbidden[i]) {
                maxCnt = max(maxCnt, ++mp[nums[i]]);
                totalCnt++;
            }
        }
        return max((totalCnt + 1) / 2, maxCnt);
    }
};
