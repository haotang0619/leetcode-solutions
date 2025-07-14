class Solution {
public:
    // Searched KMP from Google
    void getLPS(string p, vector<int> &lps) {
        int k = 0, size = p.size();
        lps.push_back(0);
        for(int i = 1; i < size; i++) {
            while(k > 0 && p[k] != p[i]) k = lps[k - 1];
            if(p[k] == p[i]) k++;
            lps.push_back(k);
        }
    }

    void kmp(string text, string p, vector<int> &pos) {
        vector<int> lps;
        getLPS(p, lps);
        int matched_pos = 0;
        for(int current = 0; current < text.size(); current++) {
            while (matched_pos > 0 && p[matched_pos] != text[current]) {
                matched_pos = lps[matched_pos - 1];
            }

            if(p[matched_pos] == text[current]) matched_pos++;

            if(matched_pos == p.size()) {
                pos.push_back(current - (p.size() - 1));
                matched_pos = lps[matched_pos - 1];
            }
        }
    }

    int shortestMatchingSubstring(string s, string p) {
        vector<vector<int>> v;
        vector<string> vs;
        string tmp = "";
        for(auto x : p) {
            if(x == '*') {
                if(tmp != "") vs.push_back(tmp);
                tmp = "";
            } else tmp += x;
        }
        if(tmp != "") vs.push_back(tmp);
        for(auto x : vs) {
            vector<int> pos;
            kmp(s, x, pos);
            v.push_back(pos);
        }
        
        if(v.size() == 0) return 0;
        if(v.size() == 1) return v[0].size() > 0 ? vs[0].size() : -1;
        if(v.size() == 2) {
            int i = 0, j = 0, l1 = vs[0].size(), l2 = vs[1].size(), ans = INT_MAX;
            while(i < v[0].size()) {
                while(j < v[1].size() && v[0][i] + l1 > v[1][j]) j++;
                if(j >= v[1].size()) break;
                ans = min(ans, v[1][j] + l2 - v[0][i]);
                i++;
            }
            return ans == INT_MAX ? -1 : ans;
        }
        int i = 0, j = 0, k = 0, l1 = vs[0].size(), l2 = vs[1].size(), l3 = vs[2].size(), ans = INT_MAX;
        while(i < v[0].size()) {
            while(j < v[1].size() && v[0][i] + l1 > v[1][j]) j++;
            if(j >= v[1].size()) break;
            while(k < v[2].size() && v[1][j] + l2 > v[2][k]) k++;
            if(k >= v[2].size()) break;
            ans = min(ans, v[2][k] + l3 - v[0][i]);
            i++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
