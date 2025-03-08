class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while(k--) {
            int add = pq.top();
            pq.pop();
            ans += (long long)add;
            pq.push(add % 3 == 0 ? (add / 3) : (add / 3 + 1));
        }
        return ans;
    }
};
