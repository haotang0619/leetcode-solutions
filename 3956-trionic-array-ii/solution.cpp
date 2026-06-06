class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        // type 0: same, 1: asc, 2: desc
        // tuple: type, start, {sum as 1st part, sum as 3rd part}
        vector<tuple<int, long long, pair<long long, long long>>> v;
        int n = nums.size(), type = -1;
        cout << n << endl;
        if(nums[1] == nums[0]) type = 0;
        else if(nums[1] > nums[0]) type = 1;
        else type = 2;
        long long start = nums[0], sum = (long long)nums[0] + nums[1];
        long long maxSum = sum;
        long long negSum = (start < 0 ? start : 0) + (nums[1] < 0 ? nums[1] : 0);

        for(int i = 2; i < n; i++) {
            int newType = -1;
            if(nums[i] == nums[i - 1]) newType = 0;
            else if(nums[i] > nums[i - 1]) newType = 1;
            else newType = 2;
            
            if(type == newType) {
                sum += nums[i];
                maxSum = max(maxSum, sum);
                if(nums[i] < 0) negSum += nums[i];
            } else {
                if(type == 1) {
                    long long preSum = sum - negSum;
                    if(nums[i - 2] < 0) preSum += nums[i - 2];
                    if(nums[i - 1] < 0) preSum += nums[i - 1];
                    v.push_back({type, start, {preSum, maxSum}});
                } else v.push_back({type, start, {sum, sum}});
                start = nums[i - 1];
                sum = start + nums[i];
                maxSum = sum;
                negSum = (start < 0 ? start : 0) + (nums[i] < 0 ? nums[i] : 0);
            }
            type = newType;
        }
        if(type == 1) {
            long long preSum = sum - negSum;
            if(nums[n - 2] < 0) preSum += nums[n - 2];
            if(nums[n - 1] < 0) preSum += nums[n - 1];
            v.push_back({type, start, {preSum, maxSum}});
        } else v.push_back({type, start, {sum, sum}});
        
        long long ans = -1e15;
        for(int i = 0; i < v.size() - 2; i++) {
            auto [t1, s1, sum1] = v[i];
            auto [t2, s2, sum2] = v[i + 1];
            auto [t3, s3, sum3] = v[i + 2];
            if(t1 == 1 && t2 == 2 && t3 == 1) {
                ans = max(ans, sum1.first + sum2.first + sum3.second - s2 - s3);
            }
        }
        return ans;
    }
};
