class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnts1(26, 0), cnts2(26, 0);
        for(auto& c : s1) cnts1[c - 'a']++;
        for(int i = 0; i < s2.size(); i++) {
            cnts2[s2[i] - 'a']++;
            if(i >= s1.size()) cnts2[s2[i - s1.size()] - 'a']--;
            if(i >= s1.size() - 1) {
                bool valid = true;
                for(int i = 0; i < 26; i++) {
                    if(cnts1[i] != cnts2[i]) {
                        valid = false;
                        break;
                    }
                }
                if(valid) return true;
            }
        }
        return false;
    }
};
