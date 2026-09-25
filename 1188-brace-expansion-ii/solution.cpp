class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<char> sk;
        vector<string> postfix;
        
        auto process = [&](char c) {
            if(c >= 'a' && c <= 'z') postfix.push_back({c});
            else if(c == '+') {
                while(!sk.empty() && sk.top() != '(') {
                    postfix.push_back({sk.top()}), sk.pop();
                }
                sk.push(c);
            } else if(c == '*') {
                while(!sk.empty() && sk.top() != '+' && sk.top() != '(') {
                    postfix.push_back({sk.top()}), sk.pop();
                }
                sk.push(c);
            } else if(c == '(') sk.push({c});
            else {
                // c == ')'
                while(sk.top() != '(') postfix.push_back({sk.top()}), sk.pop();
                sk.pop();
            }
        };

        char prev = '\0';
        for(auto& c : expression) {
            if(c >= 'a' && c <= 'z') {
                // Put a '*' first
                if(prev == '}' || prev >= 'a' && prev <= 'z') process('*');
                process(c);
            } else if(c == ',') process('+');
            else if(c == '{') {
                // Put a '*' first
                if(prev == '}' || prev >= 'a' && prev <= 'z') process('*');
                process('(');
            } else process(')');
            prev = c;
        }
        while(!sk.empty()) postfix.push_back({sk.top()}), sk.pop();
        // for(auto& s : postfix) cout << s << " ";
        
        using ss = set<string>;
        stack<set<string>> sk1;
        for(auto& s : postfix) {
            if(s == "+") {
                auto st2 = sk1.top();
                sk1.pop();
                auto st1 = sk1.top();
                sk1.pop();
                st1.insert(st2.begin(), st2.end());
                sk1.push(st1);
            } else if(s == "*") {
                auto st2 = sk1.top();
                sk1.pop();
                auto st1 = sk1.top();
                sk1.pop();
                ss st3;
                for(auto& s1 : st1) {
                    for(auto& s2 : st2) st3.insert(s1 + s2);
                }
                sk1.push(st3);
            } else sk1.push({s});
        }
        auto& ans = sk1.top();
        return vector<string>(ans.begin(), ans.end());
    }
};
