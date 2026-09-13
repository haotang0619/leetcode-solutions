class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = n - 1; j < n; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = -(nums[i] + nums[j]);
                while(k > j && nums[k] > left) k--;
                if(k <= j) break;
                if(nums[k] == left) ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};
