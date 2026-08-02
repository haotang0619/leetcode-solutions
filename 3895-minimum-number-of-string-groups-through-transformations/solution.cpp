class Solution {
public:
    using ull = unsigned long long;
    ull base = 131;

    int rollingHash(string& s) {
        int n = s.size(), len = n / 2;
        vector<ull> rh(n + 1, 0), pows(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            rh[i] = rh[i - 1] * base + (s[i - 1] - 'a' + 1);
            pows[i] = pows[i - 1] * base;
        }
        int ans = 0;
        for(int j = 1; j < len; j++) {
            int l = 0, r = len;
            while(l < r) {
                int m = l + (r - l + 1) / 2;
                ull rh1 = rh[ans + m] - rh[ans] * pows[m];
                ull rh2 = rh[j + m] - rh[j] * pows[m];
                if(rh1 == rh2) l = m;
                else r = m - 1;
            }
            if(l == len) continue;
            if(s[j + l] < s[ans + l]) ans = j;
        }
        return ans;
    }
    
    int minimumGroups(vector<string>& words) {
        unordered_set<string> st;
        for(auto& word : words) {
            if(word.size() <= 2) {
                st.insert(word);
                continue;
            }
            string even, odd;
            for(int i = 0; i < word.size(); i++) {
                if(i % 2 == 0) even += word[i];
                else odd += word[i];
            }
            even += even, odd += odd;
            int idx1 = rollingHash(even), idx2 = rollingHash(odd);
            string newWord;
            for(int i = 0; i < word.size(); i++) {
                if(i % 2 == 0) newWord += even[idx1 + i / 2];
                else newWord += odd[idx2 + i / 2];
            }
            st.insert(newWord);
        }
        return st.size();
    }
};
