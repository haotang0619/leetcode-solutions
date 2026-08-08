class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int removed = target;
        for(auto num : nums) removed ^= num;
        if(removed == 0) return 0;
        
        int n = nums.size();
        int ans = n + 1;
        vector<unordered_set<int>> v(n + 1);
        v[0].insert(0);
        for(int i = 0; i < n; i++) {
            for(int r = i + 1; r >= 1; r--) {
                for(auto& prev : v[r - 1]) {
                    int now = prev ^ nums[i];
                    if(removed == now) ans = min(ans, r);
                    v[r].insert(now);
                }
            }
        }
        return (ans == n + 1) ? -1 : ans;
    }
};
