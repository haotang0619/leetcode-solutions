class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> arr(2e4 + 7, 0);
        for(auto &x : nums) arr[x + 1e4]++;
        int now = 0;
        for(int i = 2e4 + 6; i >= 0; i--) {
            now += arr[i];
            if(now >= k) return i - 1e4;
        }
        return -1e4;
    }
};
