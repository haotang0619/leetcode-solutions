class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        vector<int> coll(k, false);
        for(int i = n - 1; i >= 0; i--) {
            int x = nums[i] - 1;
            if(x < k && !coll[x]) coll[x] = true, cnt++;
            if(cnt == k) return n - i;
        }
        return n;
    }
};
