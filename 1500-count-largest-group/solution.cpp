class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int max_cnt = 0;
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            for(auto x : to_string(i)) cnt += x - '0';
            if(mp.find(cnt) == mp.end()) mp[cnt] = 0;
            mp[cnt]++;
            max_cnt = max(max_cnt, mp[cnt]);
        }
        int ans = 0;
        for(auto x : mp) ans += x.second == max_cnt ? 1 : 0;
        return ans;
    }
};
