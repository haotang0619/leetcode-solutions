class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans = 0, n = nums.size();
        double thres = (double) a / b;
        for(int i = 0; i < n; i++) {
            int ecnt = 0, ocnt = 0;
            for(int j = i; j < n; j++) {
                if(nums[j] % 2 == 0) ecnt++;
                else ocnt++;
                if(ocnt > 0) {
                    double r = (double)ecnt / ocnt;
                    if(r <= thres) ans++;
                }
            }
        }
        return ans;
    }
};
