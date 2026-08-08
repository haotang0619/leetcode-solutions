class Solution {
public:
    pair<int, int> getLenMed(vector<vector<int>>& lists, int num) {
        vector<pair<int, int>> idxs;
        int i = 0, len = 0;
        while(num > 0) {
            if(num & 1) idxs.push_back({i, 0}), len += lists[i].size();
            i++, num >>= 1;
        }
        int cnt = 0, target = (len - 1) / 2, med;
        while(cnt <= target) {
            int pos = -1;
            int mn = INT_MAX;
            for(int p = 0; p < idxs.size(); p++) {
                auto& [i, idx] = idxs[p];
                if(idx < lists[i].size() && lists[i][idx] < mn) {
                    mn = lists[i][idx], pos = p;
                }
            }
            auto& [i, idx] = idxs[pos];
            med = lists[i][idx++];
            cnt++;
        }
        return {len, med};
    }

    int count(int num) {
        int cnt = 0;
        while(num > 0) cnt += (num & 1), num >>= 1;
        return cnt;
    }

    void traverse(vector<int>& child, int now, int num, int b) {
        if(num == 0) {
            if(now > 0) child.push_back(now);
            return;
        }
        traverse(child, now, num >> 1, b * 2);
        if(num & 1) traverse(child, now + b, num >> 1, b * 2);
    }
    
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        int total = (1 << n) - 1;
        vector<pair<int, int>> v(total + 1); // [len, med]
        for(int i = 1; i <= total; i++) v[i] = getLenMed(lists, i);
        vector<long long> dp(total + 1, LLONG_MAX);
        for(int i = 0; i < n; i++) dp[1 << i] = 0;
        vector<int> arr(total + 1);
        iota(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end(), [&](auto& a, auto& b) {
            return count(a) < count(b);
        });
        for(auto& num : arr) {
            vector<int> child;
            traverse(child, 0, num, 1);
            for(auto& c1 : child) {
                int c2 = num - c1;
                if(c1 > c2) continue;
                auto& [leni, medi] = v[c1];
                auto& [lenj, medj] = v[c2];
                long long cost = leni + lenj + abs(medi - medj);
                dp[num] = min(dp[num], dp[c1] + dp[c2] + cost);
            }
        }
        return dp[total];
    }
};
