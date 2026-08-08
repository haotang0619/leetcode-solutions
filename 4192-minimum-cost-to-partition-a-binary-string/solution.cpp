class Solution {
public:
    long long traverse(vector<int>& pSum, string& s, int& encCost, int& flatCost, int l, int r) {
        long long len = r - l + 1;
        long long cnt = pSum[r + 1] - pSum[l];
        long long cost = (cnt == 0) ? flatCost : (len * cnt * encCost);
        if(len % 2 == 1) return cost;
        int m = l + (r - l) / 2;
        long long lCost = traverse(pSum, s, encCost, flatCost, l, m);
        long long rCost = traverse(pSum, s, encCost, flatCost, m + 1, r);
        return min(cost, lCost + rCost);
    }
    
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + (s[i - 1] == '1');
        return traverse(pSum, s, encCost, flatCost, 0, n - 1);
    }
};
