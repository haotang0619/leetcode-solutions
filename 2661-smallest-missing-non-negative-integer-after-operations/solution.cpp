class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> modCnts(value, 0);
        for(auto& num : nums) {
            int mod = num % value;
            if(mod < 0) mod += value;
            modCnts[mod]++;
        }
        int mn = INT_MAX, mx = INT_MIN, mnIdx = -1;
        for(int i = 0; i < value; i++) {
            if(modCnts[i] < mn) mn = modCnts[i], mnIdx = i;
            mx = max(mx, modCnts[i]);
        }
        return value * modCnts[mnIdx] + mnIdx;
    }
};
