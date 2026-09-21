class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;
        for(long long i = 1; pow(i, 3) <= n; i++) {
            for(long long j = i; pow(i, 3) + pow(j, 3) <= n; j++) {
                mp[pow(i, 3) + pow(j, 3)]++;
            }
        }
        vector<int> ans;
        for(auto& [num, cnt] : mp) {
            if(cnt >= 2) ans.push_back(num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
