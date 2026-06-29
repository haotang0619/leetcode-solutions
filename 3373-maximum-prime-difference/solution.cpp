class Solution {
public:
    int n = 100;
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> isPrime(n + 1, true);
        isPrime[1] = false;
        for(int i = 2; i <= n; i++) {
            if(!isPrime[i]) continue;
            for(int j = i + i; j <= n; j += i) isPrime[j] = false;
        }
        int i1 = -1, i2 = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(isPrime[nums[i]]) {
                if(i1 == -1) i1 = i;
                i2 = i;
            }
        }
        return i2 - i1;
    }
};
