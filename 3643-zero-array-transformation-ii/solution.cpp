class Solution {
public:
    // Checked Solution => Difference Array
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 1, right = queries.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(nums, queries, mid)) right = mid;
            else left = mid + 1;
        }
        if(left == queries.size() && !isValid(nums, queries, left)) return -1;
        if(left == 1) return isValid(nums, queries, 0) ? 0 : 1;
        return left;
    }

private:
    bool isValid(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> dec(nums.size() + 1, 0);
        for(int i = 0; i < k; i++) {
            vector<int> x = queries[i];
            dec[x[0]] += x[2];
            dec[x[1] + 1] -= x[2];
        }
        for(int i = 0, sum = 0; i < nums.size(); i++) {
            sum += dec[i];
            if(nums[i] > sum) return false;
        }
        return true;
    }
};
