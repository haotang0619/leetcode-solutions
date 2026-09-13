class Solution {
public:
    bool checkSymmetric(vector<int>& cnts, int& n) {
        int oddCnt = 0;
        for(int c = 0; c < 26; c++) oddCnt += (cnts[c] % 2);
        if(n % 2 == 0) return oddCnt == 0;
        return oddCnt == 1;
    }

    string buildRes(string& ans, int& n) {
        string rev = ans;
        if(n % 2 == 1) rev.pop_back();
        reverse(rev.begin(), rev.end());
        return ans + rev;
    }

    bool findAns(vector<int>& cnts, string& ans, string& target, int idx) {
        int n = target.size();
        if(idx == (n + 1) / 2) {
            string res = buildRes(ans, n);
            return res > target;
        }

        int start = target[idx] - 'a';
        for(int c = start; c < 26; c++) {
            int need = 2;
            if(n % 2 == 1 && idx == n / 2) need = 1;
            if(cnts[c] < need) continue;
            
            ans += ('a' + c);
            cnts[c] -= need;
            
            if(c == start) {
                bool res = findAns(cnts, ans, target, idx + 1);
                if(res) return true;
            } else {
                int mid = -1;
                for(int c = 0; c < 26; c++) {
                    for(int x = 2; x <= cnts[c]; x += 2) ans += ('a' + c);
                    if(cnts[c] % 2 == 1) mid = c;
                }
                if(mid >= 0) ans += ('a' + mid);
                return true;
            }
            
            ans.pop_back();
            cnts[c] += need;
        }
        return false;
    }
    
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnts(26, 0);
        for(auto& c : s) cnts[c - 'a']++;
        int n = target.size();
        if(!checkSymmetric(cnts, n)) return "";
        
        string ans = "";
        if(findAns(cnts, ans, target, 0)) return buildRes(ans, n);
        return "";
    }
};
