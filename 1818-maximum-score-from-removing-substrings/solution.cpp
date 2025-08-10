class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string good = x > y ? "ab" : "ba";
        int i = 0, ans = 0;
        while(i < s.size()) {
            if(s[i] != 'a' && s[i] != 'b') {
                i++;
                continue;
            } else {
                int j = i;
                stack<char> sk;
                while(j <= s.size()) {
                    if(j == s.size() || s[j] != 'a' && s[j] != 'b') {
                        int cnt1 = 0, cnt2 = 0;
                        while(!sk.empty()) {
                            char top = sk.top();
                            sk.pop();
                            top == 'a' ? cnt1++ : cnt2++;
                        }
                        int p = good == "ab" ? y : x;
                        ans += p * min(cnt1, cnt2);
                        break;
                    } else {
                        char a = good == "ab" ? 'a' : 'b';
                        char b = good == "ab" ? 'b' : 'a';
                        int p = good == "ab" ? x : y;
                        if(s[j] == a) sk.push(a);
                        else {
                            if(!sk.empty() && sk.top() == a) {
                                sk.pop();
                                ans += p;
                            } else sk.push(b);
                        }
                        j++;
                    }
                }
                i = j + 1;
            }
        }
        return ans;
    }
};
