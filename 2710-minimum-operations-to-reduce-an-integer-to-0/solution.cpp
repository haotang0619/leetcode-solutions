class Solution {
public:
    int minOperations(int n) {
        string s = bitset<19>(n).to_string();
        int ans = 0, cnt = 0;
        for(int i = 18; i >= 0; i--) {
            if(s[i] == '1') cnt++;
            else {
                if(cnt >= 2) ans++, cnt = 1;
                else if(cnt == 1) ans++, cnt = 0;
            }
        }
        return ans;
    }
};
