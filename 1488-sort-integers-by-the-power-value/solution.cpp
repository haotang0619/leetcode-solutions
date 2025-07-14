class Solution {
public:
    int getPower(int x) {
        int cnt = 0;
        while(x > 1) {
            cnt++;
            x = x % 2 == 0 ? (x / 2) : (3 * x + 1);
        }
        return cnt;
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> power;
        for(int i = lo; i <= hi; i++) power.push_back({getPower(i), i});

        sort(power.begin(), power.end());
        return power[k - 1].second;
    }
};
