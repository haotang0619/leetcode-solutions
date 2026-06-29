class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0, cost = 0, n = nums.size();
        for(int i = 0, j = 0; j < n; i++) {
            while(j < n) {
                int cost1 = nums[i] - nums[j];
                if(cost + cost1 <= k) cost += cost1;
                else break;
                j++;
            }
            ans = max(ans, j - i);
            if(i < n - 1 && i + 1 < j) {
                int modified = j - i - 1;
                cost -= modified * (nums[i] - nums[i + 1]);
            }
        }
        return ans;
    }
};
