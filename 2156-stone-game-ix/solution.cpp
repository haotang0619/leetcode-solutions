class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnts(3, 0);
        for(auto& st : stones) cnts[st % 3]++;
        if(cnts[1] > 0) {
            // 1, 1, 2, 1, 2...
            if((cnts[2] > cnts[1] - 1) && (cnts[0] % 2 == 0)) return true;
            // 1, 1, 0, 2, 1, 2, 1...
            if(cnts[0] % 2 == 1 && cnts[1] >= 2) {
                if((cnts[1] - 2 > cnts[2]) && ((cnts[0] - 1) % 2 == 0)) return true;
            }
        }
        if(cnts[2] > 0) {
            // 2, 2, 1, 2, 1...
            if((cnts[1] > cnts[2] - 1) && (cnts[0] % 2 == 0)) return true;
            // 2, 2, 0, 1, 2, 1, 2...
            if(cnts[0] % 2 == 1 && cnts[2] >= 2) {
                if((cnts[2] - 2 > cnts[1]) && ((cnts[0] - 1) % 2 == 0)) return true;
            }
        }
        return false;
    }
};
