class Solution {
public:
    vector<int> pSum;
    mt19937 gen;
    uniform_int_distribution<int> distrib;

    Solution(vector<int>& w) : gen(random_device{}()) {
        int n = w.size();
        pSum.resize(n);
        for(int i = 0; i < n; i++) pSum[i] = w[i] + (i > 0 ? pSum[i - 1] : 0);
        distrib = uniform_int_distribution<int>(1, pSum.back());
    }
    
    int pickIndex() {
        int num = distrib(gen);
        int idx = lower_bound(pSum.begin(), pSum.end(), num) - pSum.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
