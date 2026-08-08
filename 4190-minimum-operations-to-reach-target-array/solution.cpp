class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](auto& a, auto& b) {
            return nums[a] < nums[b];
        });
        int ans = 0, prev = -1;
        bool need = false;
        for(auto& idx : indices) {
            if(nums[idx] != prev) {
                if(need) ans++;
                need = false;
            }
            prev = nums[idx];
            if(nums[idx] != target[idx]) need = true;
        }
        if(need) ans++;
        return ans;
    }
};
