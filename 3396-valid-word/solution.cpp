class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int vcnt = 0, ccnt = 0;
        for(auto x : word) {
            if(x >= 'a' && x <= 'z') {
                if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                    vcnt++;
                } else ccnt++;
            } else if (x >= 'A' && x <= 'Z') {
                if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
                    vcnt++;
                } else ccnt++;
            } else if(x < '0' || x > '9') return false;
        }
        return vcnt >= 1 && ccnt >= 1;
    }
};
