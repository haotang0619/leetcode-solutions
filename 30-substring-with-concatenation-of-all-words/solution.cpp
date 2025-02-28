class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].length();
        int wordsSize = words.size();
        int totalLen = wordLen * wordsSize;
        vector<int> ans;
        if(s.length() < totalLen) return ans;

        map<string, int> mp1;
        for(auto x : words) mp1[x]++;
        
        for(int x = 0; x < wordLen; x++) {
            map<string, int> mp2;
            for(int i = x; i + wordLen <= s.length(); i += wordLen) {
                mp2[s.substr(i, wordLen)]++;
                if(i - x >= totalLen) {
                    mp2[s.substr(i - totalLen, wordLen)]--;
                    if(mp2[s.substr(i - totalLen, wordLen)] == 0) {
                        mp2.erase(s.substr(i - totalLen, wordLen));
                    }
                }
                if(mp1 == mp2) ans.push_back(i - totalLen + wordLen);
            }
        }
        return ans;
    }
};
