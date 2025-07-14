class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        stack<int> sk_min;
        sk_min.push(nums.back());
        for(int i = nums.size() - 2; i >= 2; i--) {
            sk_min.push(min(sk_min.top(), nums[i]));
        }
        int ans = 0, max_now = nums[0];
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] > max_now && nums[i] < sk_min.top()) {
                ans += 2;
            } else if(nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                ans++;
            }
            max_now = max(max_now, nums[i]);
            sk_min.pop();
        }
        return ans;
    }
};
