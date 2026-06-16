class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n + 1);
        for(int &x : ans) x = 1;
        for(int &x : nums) ans[x] = 0;
        for(int i = 0, j = 1; j <= n; j++) {
            if(ans[j]) ans[i++] = j;
            if(j == n) {
                for(int k = n; k >= i; k--) ans.erase(ans.begin() + k);
            }
        }
        return ans;
    }
};
