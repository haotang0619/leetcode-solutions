class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // 1. First and last numbers are fixed
        // 2. Pick k - 1 pairs of consecutive numbers
        int n = weights.size();
        vector<long long> v;
        for(int i = 0; i < n - 1; i++) v.push_back(weights[i] + weights[i + 1]);
        sort(v.begin(), v.end());
        long long c1 = accumulate(v.begin(), v.begin() + (k - 1), 0LL);
        long long c2 = accumulate(v.end() - (k - 1), v.end(), 0LL);
        return c2 - c1;
    }
};
