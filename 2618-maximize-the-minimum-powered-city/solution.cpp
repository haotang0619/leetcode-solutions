class Solution {
public:
    bool check(vector<long long>& powers, long long& minPower, int& r, int k) {
        queue<pair<int, long long>> qu; // [end_idx, added]
        long long added = 0;
        int n = powers.size();
        for(int i = 0; i < n; i++) {
            while(!qu.empty() && qu.front().first < i) {
                added -= qu.front().second;
                qu.pop();
            }
            if(powers[i] + added >= minPower) continue;
            long long diff = minPower - (powers[i] + added);
            if(diff > k) return false;
            k -= diff, added += diff;
            qu.push({min(i + r * 2, n - 1), diff});
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int range, int k) {
        int n = stations.size();
        vector<long long> diff(n + 1, 0);
        for(int i = 0; i < n; i++) {
            diff[max(0, i - range)] += stations[i];
            diff[min(n, i + range + 1)] -= stations[i];
        }
        vector<long long> pSum(n, 0);
        for(int i = 0; i < n; i++) {
            pSum[i] = diff[i] + (i > 0 ? pSum[i - 1] : 0);
        }

        long long l = 0, r = 1e14;
        while(l < r) {
            long long m = l + (r - l + 1) / 2;
            if(check(pSum, m, range, k)) l = m;
            else r = m - 1;
        }
        return l;
    }
};
