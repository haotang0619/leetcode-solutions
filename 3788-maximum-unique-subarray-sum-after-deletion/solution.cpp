class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> seen;
        int ans = 0, maxNum = -101;
        bool flag = false;
        for(auto x : nums) {
            maxNum = max(x, maxNum);
            if(x > 0 && seen.count(x) == 0) {
                flag = true;
                seen.insert(x);
                ans += x;
            }
        }
        return flag ? ans : maxNum;
    }
};
