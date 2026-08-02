class Solution {
public:
    bool check(int num) {
        string s;
        while(num > 0) {
            s += ('0' + (num & 1));
            num >>= 1;
        }
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s == s1;
    }
    
    vector<int> minOperations(vector<int>& nums) {
        vector<int> arr;
        for(int i = 0; i <= 8193; i++) {
            if(check(i)) arr.push_back(i);
        }
        int n = nums.size();
        vector<int> ans(n, INT_MAX);
        for(int i = 0; i < n; i++) {
            int idx = upper_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            if(idx < arr.size()) ans[i] = arr[idx] - nums[i];
            if(idx - 1 >= 0) ans[i] = min(ans[i], nums[i] - arr[idx - 1]);
        }
        return ans;
    }
};
