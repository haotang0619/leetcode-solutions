class Solution {
public:
    // Saw all hints
    long long minimumDifference(vector<int>& nums) {
        int size = nums.size(), n = size / 3;
        long long lSum = 0, rSum = 0;
        vector<long long> vSum1(size, 1e12), vSum2(size, -1e12);
        priority_queue<long long> pq1;
        priority_queue<long long, vector<long long>, greater<long long>> pq2;
        for(int i = 0; i < size; i++) {
            lSum += nums[i];
            pq1.push(nums[i]);
            if(pq1.size() > n) {
                lSum -= pq1.top();
                pq1.pop();
            }
            if(pq1.size() == n) vSum1[i] = lSum;
        }
        for(int i = size - 1; i >= 0; i--) {
            rSum += nums[i];
            pq2.push(nums[i]);
            if(pq2.size() > n) {
                rSum -= pq2.top();
                pq2.pop();
            }
            if(pq2.size() == n) vSum2[i] = rSum;
        }
        long long ans = 1e12;
        for(int i = 0; i < size - 1; i++) {
            ans = min(ans, vSum1[i] - vSum2[i + 1]);
        }
        return ans;
    }
};
