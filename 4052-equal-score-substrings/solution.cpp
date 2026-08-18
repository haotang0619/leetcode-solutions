class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0, now = 0;
        for(auto& c : s) sum += (c - 'a' + 1);
        for(auto& c : s) {
            now += (c - 'a' + 1);
            if(now * 2 == sum) return true;
        }
        return false;
    }
};
