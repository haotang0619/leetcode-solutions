class Solution {
public:
    int rotatedDigits(int n) {
        map<char, char> mp;
        mp['0'] = '0';
        mp['1'] = '1';
        mp['2'] = '5';
        mp['5'] = '2';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            string s = to_string(i);
            bool valid = true;
            for(auto &c : s) {
                if(!mp.contains(c)) {
                    valid = false;
                    break;
                }
                c = mp[c];
            }
            if(valid) valid = stoi(s) != i;
            if(valid) cnt++;
        }
        return cnt;
    }
};
