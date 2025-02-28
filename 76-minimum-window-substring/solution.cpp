class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1;
        for(auto x : t) mp1[x]++;
        
        unordered_map<char, int> mp2;
        unordered_set<char> st;
        int idx1 = 0, idx2 = 0;
        string ans = "";

        while(st.size() != mp1.size()) {
            mp2[s[idx2]]++;
            if(mp1.find(s[idx2]) != mp1.end() && mp2[s[idx2]] >= mp1[s[idx2]]){
                st.insert(s[idx2]);
            }
            idx2++;
            if(idx2 >= s.length()) break;
        }
        if(st.size() != mp1.size()) return ans;

        vector<int> ans_idx = {-1, -1};
        char prev = '\0';
        while(idx2 <= s.length()) {
            bool isValid = true;
            if(prev != '\0') {
                while(true) {
                    mp2[s[idx2]]++;
                    idx2++;
                    if(s[idx2 - 1] == prev) break;
                    if(idx2 >= s.length()) {
                        isValid = false;
                        break;
                    }
                }
            }
            
            if(isValid) {
                while(true) {
                    mp2[s[idx1]]--;
                    if(mp2[s[idx1]] == 0) mp2.erase(s[idx1]);
                    if(mp2[s[idx1]] < mp1[s[idx1]]) {
                        prev = s[idx1];
                        break;
                    }
                    idx1++;
                }
                if(ans_idx[0] == -1 || idx2 - idx1 < ans_idx[1]) {
                    ans_idx = {idx1, idx2 - idx1};
                }
                idx1++;
            }

        }
        if(ans_idx[0] != -1) ans = s.substr(ans_idx[0], ans_idx[1]);
        return ans;
    }
};
