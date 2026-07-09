class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp1, mp2;
        for(auto& c : p) mp1[c]++;
        int n = s.size(), m = p.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            mp2[s[i]]++;
            if(i >= m) mp2[s[i - m]]--;
            if(i >= m - 1) {
                bool valid = true;
                for(char c = 'a'; c <= 'z'; c++) {
                    if(mp1[c] != mp2[c]) {
                        valid = false;
                        break;
                    }
                }
                if(valid) ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};
