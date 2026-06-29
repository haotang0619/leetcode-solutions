class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int now = 0, n = s.size(), p = (1 << k);
        for(int i = 0; i < n; i++) {
            now = (now << 1) + (s[i] - '0');
            if(i >= k) now -= (s[i - k] - '0') * p;
            if(i >= k - 1) st.insert(now);
        }
        return st.size() == p;
    }
};
