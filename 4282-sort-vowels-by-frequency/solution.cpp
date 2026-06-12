class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<int> pos;
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        vector<vector<int>> cnt(5, vector<int>({0, -n}));
        map<char, int> mp;
        mp['a'] = 0; mp['e'] = 1; mp['i'] = 2; mp['o'] = 3; mp['u'] = 4;
        for(int i = 0; i < 5; i++) cnt[i].push_back(i);
        for(int i = 0; i < n; i++) {
            int idx = -1;
            if(mp.contains(s[i])) idx = mp[s[i]];
            if(idx >= 0) {
                cnt[idx][0]++;
                if(cnt[idx][1] == -n) cnt[idx][1] = -i;
                pos.push_back(i);
            }
        }
        sort(cnt.begin(), cnt.end(), greater<vector<int>>());
        int idx = 0;
        for(auto p : pos) {
            while(cnt[idx][0] == 0) idx++;
            s[p] = v[cnt[idx][2]];
            cnt[idx][0]--;
        }
        return s;
    }
};
