class Solution {
public:
    string smallestSubsequence(string s) {
        set<char> st;
        for(auto x : s) st.insert(x);
        int start = 0;
        string ans = "";

        set<char> st1;
        while(ans.length() < st.size()) {
            for(auto x : st) {
                if(st1.find(x) == st1.end()) {
                    set<char> st2;
                    int target_size = st.size() - st1.size() - 1;
                    bool flag = false;
                    int curr = start;
                    for(int i = start; i < s.length(); i++) {
                        char y = s[i];
                        if(y == x) {
                            if(!flag) curr = i;
                            flag = true;
                        } else if(flag && st1.find(y) == st1.end()) {
                            st2.insert(y);
                            if(st2.size() == target_size) break;
                        }
                    }
                    if(st2.size() == target_size) {
                        start = curr;
                        st1.insert(x);
                        ans.push_back(x);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
