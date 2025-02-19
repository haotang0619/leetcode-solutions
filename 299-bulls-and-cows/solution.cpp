class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, pair<int, int>> mp;
        map<int, int> mp2;
        for (int i = 0; i < secret.size(); i++) {
            mp[secret[i]].first++;
            if (secret[i] == guess[i]) mp[secret[i]].second++;
            mp2[guess[i]]++;
        }
    
        int bulls = 0, cows = 0;
        for (auto x : mp) {
            if (x.second.second > 0) bulls += x.second.second;
            cows += max(0, min(mp2[x.first], x.second.first) - x.second.second);
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
