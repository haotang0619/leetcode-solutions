class Solution {
public:
    void findAll(bool &ans, string &now, vector<int> &num, vector<bool> &took) {
        if(ans) return;
        if(now.size() == num.size()) {
            int res = stoi(now);
            double l1 = log2(res), l2 = floor(l1);
            if(l1 == l2) ans = true;
            return;
        }
        for(int i = 0; i < num.size(); i++) {
            if(took[i]) continue;
            if(now.size() == 0 && num[i] == 0) continue;
            now += '0' + num[i];
            took[i] = true;
            findAll(ans, now, num, took);
            took[i] = false;
            now.pop_back();
        }
    }

    bool reorderedPowerOf2(int n) {
        vector<int> num;
        while(n > 0) {
            num.push_back(n % 10);
            n /= 10;
        }
        bool ans = false;
        string now = "";
        vector<bool> took(num.size(), false);
        findAll(ans, now, num, took);
        return ans;
    }
};
