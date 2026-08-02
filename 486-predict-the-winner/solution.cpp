class Solution {
public:
    int traverse(vector<int>& nums, vector<int>& pSum, map<pair<int, int>, int>& mp, int l, int r) {
        if(l == r) return mp[{l, r}] = nums[l];
        if(mp.contains({l, r})) return mp[{l, r}];
        int leftOpp = traverse(nums, pSum, mp, l + 1, r);
        int leftScore = pSum[r + 1] - pSum[l + 1] - leftOpp;
        int rightOpp = traverse(nums, pSum, mp, l, r - 1);
        int rightScore = pSum[r] - pSum[l] - rightOpp;
        return mp[{l, r}] = max(nums[l] + leftScore, nums[r] + rightScore);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        map<pair<int, int>, int> mp;
        int score1 = traverse(nums, pSum, mp, 0, n - 1);
        int score2 = pSum[n] - score1;
        return score1 >= score2;
    }
};
