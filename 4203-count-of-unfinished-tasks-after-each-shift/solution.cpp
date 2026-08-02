class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> pSum(n, 0);
        pSum[0] = tasks[0];
        for(int i = 1; i < n; i++) pSum[i] = pSum[i - 1] + tasks[i];
        int m = shifts.size();
        vector<int> ans(m);
        long long carry = 0;
        for(int i = 0; i < m; i++) {
            long long t = shifts[i] + carry;
            int idx = upper_bound(pSum.begin(), pSum.end(), t) - pSum.begin() - 1;
            ans[i] = n - 1 - idx;
            carry = (ans[i] == 0) ? 0 : t;
        }
        return ans;
    }
};
