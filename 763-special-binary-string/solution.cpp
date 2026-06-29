class Solution {
public:
    string makeLargestSpecial(string s) {
        stack<pair<string, bool>> sk; // [string, isSpecial]
        for(auto& c : s) {
            if(c == '1') sk.push({{c}, false});
            else {
                string now = {c};
                // Concat all special substr in the middle
                while(sk.top().second) {
                    now = sk.top().first + now;
                    sk.pop();
                }
                // Concat the previous 1 for the head
                now = sk.top().first + now;
                sk.pop();
                // Bubble it to the first special
                stack<pair<string, bool>> tmp;
                while(!sk.empty() && sk.top().second && sk.top().first < now) {
                    tmp.push(sk.top());
                    sk.pop();
                }
                sk.push({now, true});
                while(!tmp.empty()) {
                    sk.push(tmp.top());
                    tmp.pop();
                }
            }
        }
        string ans;
        while(!sk.empty()) {
            ans = sk.top().first + ans;
            sk.pop();
        }
        return ans;
    }
};
