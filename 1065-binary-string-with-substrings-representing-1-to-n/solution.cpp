class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> st;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            long long now = 0;
            for(int j = i; j < len; j++) {
                now *= 2;
                if(s[j] == '1') now += 1;
                if(now >= 1 && now <= n) st.insert(now);
                if(now > n) break;
            }
        }
        return st.size() == n;
    }
};
