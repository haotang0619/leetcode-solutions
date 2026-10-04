class Solution {
public:
    bool checkValidString(string s) {
        deque<int> pos;
        stack<int> sk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') sk.push(i);
            else if(s[i] == '*') pos.push_back(i);
            else {
                if(!sk.empty()) sk.pop();
                else if(!pos.empty()) pos.pop_front();
                else return false;
            }
        }
        while(!sk.empty()) {
            if(pos.empty()) return false;
            int top = sk.top();
            sk.pop();
            int last = pos.back();
            pos.pop_back();
            if(top > last) return false;
        }
        return true;
    }
};
