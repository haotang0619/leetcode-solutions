class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](auto& a, auto& b) {
            int num1 = nums[a], num2 = nums[b], sum1 = 0, sum2 = 0;
            while(num1 > 0) sum1 += num1 % 10, num1 /= 10;
            while(num2 > 0) sum2 += num2 % 10, num2 /= 10;
            if(sum1 != sum2) return sum1 < sum2;
            return nums[a] < nums[b];
        });
        for(int i = 0; i < n; i++) {
            while(indices[i] != i) ans++, swap(indices[i], indices[indices[i]]);
        }
        return ans;
    }
};
