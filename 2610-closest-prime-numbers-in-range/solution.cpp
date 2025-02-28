class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        unordered_map<int, bool> mp;
        mp[1] = true;
        for(int i = 2; i * i <= right; i++) {
            if(mp[i]) continue;
            for(int j = max(i + i, left / i * i); j <= right; j += i) mp[j] = true;
        }

        vector<int> v = {-1, -1};
        int prev = -1;
        for(int i = left; i <= right; i++) {
            if(!mp[i]) {
                if(prev != -1) {
                    if(v[0] == -1 || v[1] - v[0] > i - prev) {
                        v = {prev, i};
                    }
                }
                prev = i;
            }
        }
        return v;
    }
};
