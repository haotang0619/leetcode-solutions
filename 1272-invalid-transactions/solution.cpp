class Solution {
public:
    void parseTrans(vector<string>& result, string trans) {
        string now;
        int i = 0;
        for(auto& c : trans) {
            if(c == ',') result[i++] = now, now = "";
            else now += c;
        }
        result[i] = now;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        set<int> st;
        vector<string> x(4), y(4);
        for(int i = 0; i < n; i++) {
            parseTrans(x, transactions[i]);
            if(stoi(x[2]) > 1000) st.insert(i);
            for(int j = i + 1; j < n; j++) {
                parseTrans(y, transactions[j]);
                if(x[0] == y[0] && abs(stoi(x[1]) - stoi(y[1])) <= 60 && x[3] != y[3]) {
                    st.insert(i);
                    st.insert(j);
                }
            }
        }
        vector<string> ans;
        for(auto& i : st) ans.push_back(transactions[i]);
        return ans;
    }
};
