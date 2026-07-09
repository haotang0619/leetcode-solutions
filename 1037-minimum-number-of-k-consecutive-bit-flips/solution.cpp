class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        queue<int> flips; // flipped until idx
        for(int i = 0; i < n; i++) {
            while(!flips.empty() && i > flips.front()) flips.pop();
            bool rev = flips.size() % 2 == 1;
            int now = rev ? (1 - nums[i]) : nums[i];
            if(now == 0) {
                if(i + k - 1 >= n) return -1;
                ans++, flips.push(i + k - 1);
            }
        }
        return ans;
    }
};
