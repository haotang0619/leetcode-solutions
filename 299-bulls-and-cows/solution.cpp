class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0, n = secret.size();
        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) a++;
            mp1[secret[i] - '0']++;
            mp2[guess[i] - '0']++;
        }
        for(int i = 0; i <= 9; i++) b += min(mp1[i], mp2[i]);
        b -= a;
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
