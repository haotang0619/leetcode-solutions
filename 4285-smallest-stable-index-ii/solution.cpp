class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxByFar(n, INT_MIN), minByFar(n, INT_MAX);
        for(int i = 0; i < n; i++) {
            int j = n - 1 - i;
            maxByFar[i] = nums[i];
            minByFar[j] = nums[j];
            if(i > 0) {
                maxByFar[i] = max(maxByFar[i - 1], maxByFar[i]);
                minByFar[j] = min(minByFar[j + 1], minByFar[j]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(maxByFar[i] - minByFar[i] <= k) return i;
        }
        return -1;
    }
};
