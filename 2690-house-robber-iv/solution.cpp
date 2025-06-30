class Solution {
public:
    // Checked Hints & GPT
    int minCapability(vector<int>& nums, int k) {
        int left = 1, right = 1e9;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(check(k, mid, nums)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

private:
    bool check(int k, int m, vector<int>& nums) {
        int curr = -2, cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] <= m && i > curr + 1) ++cnt, curr = i;
            if(cnt == k) return true;
        }
        return false;
    }
};
