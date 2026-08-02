class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int count(string& s) {
        int cnt = 0;
        for(auto& c : s) {
            if(vowels.contains(c)) cnt++;
        }
        return cnt;
    }
    
    string reverseWords(string s) {
        vector<string> v;
        string now = "";
        for(auto& c : s) {
            if(c == ' ') {
                if(now.size() > 0) v.push_back(now);
                now = "";
            } else now += c;
        }
        if(now.size() > 0) v.push_back(now);
        if(v.size() == 0) return "";
        int cnt0 = count(v[0]);
        for(int i = 1; i < v.size(); i++) {
            int cnt = count(v[i]);
            if(cnt0 == cnt) reverse(v[i].begin(), v[i].end());
        }
        string ans;
        for(int i = 0; i < v.size(); i++) {
            ans += v[i];
            if(i < v.size() - 1) ans += ' ';
        }
        return ans;
    }
};
