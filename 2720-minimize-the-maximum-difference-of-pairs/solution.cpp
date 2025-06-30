class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(check(nums, p, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

private:
    // Checked the editorial to know that greedy works
    bool check(vector<int>& nums, int p, int m) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i + 1] - nums[i] <= m) {
                cnt++;
                i++;
            }
            if(cnt >= p) return true;
        }
        return false;
    }
};
