class Solution {
public:
    // Saw solutions
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<pair<int, int>> lefts(n + 1, {0, 0});
        for(auto &x : conflictingPairs) {
            int l = min(x[0], x[1]), r = max(x[0], x[1]);
            if(l > lefts[r].first) lefts[r].first = l;
            if(lefts[r].first > lefts[r].second) {
                swap(lefts[r].first, lefts[r].second);
            }
        }
        for(int r = 1; r <= n; r++) {
            vector<int> options = {lefts[r - 1].first, lefts[r - 1].second, lefts[r].first, lefts[r].second};
            sort(options.begin(), options.end());
            lefts[r] = {options[2], options[3]};
        }
        
        long long ans = 0, maxGain = 0;
        vector<long long> gain(n + 1, 0);
        for(int r = 1; r <= n; r++) {
            auto [l1, l2] = lefts[r];
            ans += r - l2;
            gain[l2] += l2 - l1;
            maxGain = max(maxGain, gain[l2]);
        }
        return ans + maxGain;
    }
};
