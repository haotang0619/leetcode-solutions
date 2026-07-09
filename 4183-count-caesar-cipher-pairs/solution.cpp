class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> mp;
        for(auto& w : words) {
            int diff = w[0] - 'a';
            for(auto& c : w) {
                c = (c - diff >= 'a') ? (c - diff) : (c + 26 - diff);
            }
            mp[w]++;
        }
        long long ans = 0;
        for(auto& [w, cnt] : mp) {
            if(cnt >= 2) ans += cnt * (cnt - 1) / 2;
        }
        return ans;
    }
};
