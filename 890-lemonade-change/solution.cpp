class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cnts(2, 0);
        for(auto &b : bills) {
            if(b == 5) cnts[0]++;
            else if(b == 10) {
                if(cnts[0] == 0) return false;
                cnts[0]--, cnts[1]++;
            } else {
                int left = 15;
                if(cnts[1] > 0) cnts[1]--, left = 5;
                if(cnts[0] < left / 5) return false;
                cnts[0] -= left / 5;
            }
        }
        return true;
    }
};
