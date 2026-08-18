class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26, 0);
        for(auto& c : s) freq[c - 'a']++;
        vector<string> v(101, "");
        for(int i = 0; i < 26; i++) v[freq[i]] += ('a' + i);
        string ans;
        for(int i = 100; i >= 1; i--) {
            if(v[i].size() > ans.size()) ans = v[i];
        }
        return ans;
    }
};
