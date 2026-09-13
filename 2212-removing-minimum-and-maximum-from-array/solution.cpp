class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i1 = max_element(nums.begin(), nums.end()) - nums.begin();
        int i2 = min_element(nums.begin(), nums.end()) - nums.begin();
        if(i1 > i2) swap(i1, i2);
        return min({i1 + 1 + n - i2, i2 + 1, n - i1});
    }
};
