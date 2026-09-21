class Solution {
public:
    int mirrorFrequency(string s) {
        int ans = 0;
        unordered_map<char, int> freq;
        for(auto& c : s) freq[c]++;
        for(auto& c : s) {
            if(freq[c] == 0) continue;
            char m;
            if(c >= 'a' && c <= 'z') m = (25 - (c - 'a')) + 'a';
            else m = (9 - (c - '0')) + '0';
            ans += abs(freq[c] - freq[m]);
            freq[c] = freq[m] = 0;
        }
        return ans;
    }
};
