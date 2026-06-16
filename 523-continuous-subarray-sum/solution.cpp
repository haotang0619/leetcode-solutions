class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        unordered_set<int> st;
        for(int i = 0; i <= n; i++) {
            int rem = pSum[i] % k;
            if(st.contains(rem)) return true;
            if(i >= 1) st.insert(pSum[i - 1] % k);
        }
        return false;
    }
};
