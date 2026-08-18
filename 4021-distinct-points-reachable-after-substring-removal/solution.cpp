class Solution {
public:
    string trans(int x, int y) {
        return to_string(x) + 'x' + to_string(y) + 'y';
    }

    unordered_map<char, int> mp = {{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
    
    int distinctPoints(string s, int k) {
        unordered_set<string> st;
        vector<int> cnts1(4, 0), cnts2(4, 0);
        for(auto& c : s) cnts1[mp[c]]++;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            cnts2[mp[s[i]]]++;
            if(i >= k) cnts2[mp[s[i - k]]]--;
            if(i >= k - 1) {
                int x = (cnts1[3] - cnts2[3]) - (cnts1[2] - cnts2[2]);
                int y = (cnts1[0] - cnts2[0]) - (cnts1[1] - cnts2[1]);
                st.insert(trans(x, y));
            }
        }
        return st.size();
    }
};
