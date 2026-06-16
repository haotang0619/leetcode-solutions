class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int cnt = 1, i = 2;
        while(s.size() < n) {
            int needed = s[i] - '0';
            char last = s[s.size() - 1];
            char next = last == '1' ? '2' : '1';
            while(needed-- && s.size() < n) {
                s += next;
                if(next == '1') cnt++;
            }
            i++;
        }
        return cnt;
    }
};
