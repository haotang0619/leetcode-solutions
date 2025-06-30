class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> ump;
        for(char c = 'a'; c <= 'z'; c++) ump[c] = 0;
        for(auto x : s) ump[x]++;
        stack<char> sk;
        string ans = "";
        char smallest = 'a';
        for(auto x : s) {
            while(ump[smallest] <= 0) smallest++;
            while(!sk.empty()) {
                char now = sk.top();
                if(now <= smallest) {
                    ans += now;
                    sk.pop();
                } else break;
            }
            sk.push(x);
            ump[x]--;
        }
        while(!sk.empty()) {
            ans += sk.top();
            sk.pop();
        }
        return ans;
    }
};
