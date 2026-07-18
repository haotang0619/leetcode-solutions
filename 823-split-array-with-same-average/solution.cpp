class Solution {
public:
    void picking(vector<int>& nums, vector<unordered_set<int>>& mp, int idx, int end, int cnt, int sum) {
        if(idx == end) {
            mp[cnt].insert(sum);
            return;
        }
        picking(nums, mp, idx + 1, end, cnt + 1, sum + nums[idx]);
        picking(nums, mp, idx + 1, end, cnt, sum);
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if(n == 1) return false;
        vector<unordered_set<int>> mp1(16), mp2(16);
        picking(nums, mp1, 0, n / 2, 0, 0);
        picking(nums, mp2, n / 2, n, 0, 0);
        for(int i = 1; i <= n / 2; i++) {
            if((sum * i) % n != 0) continue;
            int sum1 = sum * i / n;
            for(int j = 0; j <= i; j++) {
                for(auto& x : mp1[j]) {
                    if(mp2[i - j].contains(sum1 - x)) return true;
                }
            }
        }
        return false;
    }
};
