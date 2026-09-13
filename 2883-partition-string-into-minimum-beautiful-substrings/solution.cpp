class Solution {
public:
    bool check(int num) {
        bool valid = true;
        while(num > 1) {
            if(num % 5 != 0) {
                valid = false;
                break;
            }
            num /= 5;
        }
        return valid;
    }
    
    void traverse(string& s, int& ans, int num, int cnt, int idx) {
        num = num * 2 + (s[idx] - '0');
        if(idx == s.size() - 1) {
            if(check(num)) ans = min(ans, cnt + 1);
            return;
        }
        if(s[idx + 1] != '0' && check(num)) traverse(s, ans, 0, cnt + 1, idx + 1);
        traverse(s, ans, num, cnt, idx + 1);
    }
    
    int minimumBeautifulSubstrings(string s) {
        if(s[0] == '0') return -1;
        int ans = INT_MAX;
        traverse(s, ans, 0, 0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
