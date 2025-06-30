class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int, int> mp;
        int idx1 = 0, idx2 = 0, n = s.length();
        int ans = 0;
        while(idx2 < n) {
            while(idx2 < n && mp.size() < 3) mp[s[idx2++]]++;
            while(mp.size() >= 3) {
                ans += n - idx2 + 1;
                mp[s[idx1]]--;
                if(mp[s[idx1]] == 0) mp.erase(s[idx1]);
                idx1++;
            }
        }
        return ans;
    }
};
