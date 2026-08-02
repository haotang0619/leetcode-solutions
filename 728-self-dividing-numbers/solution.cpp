class Solution {
public:
    bool check(int& num) {
        string s = to_string(num);
        for(auto&c : s) {
            if(c == '0') return false;
            if(num % (c - '0') != 0) return false;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            if(check(i)) ans.push_back(i);
        }
        return ans;
    }
};
