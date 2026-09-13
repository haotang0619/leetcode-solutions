class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(auto& num : nums) {
            string s;
            char now = 'a';
            int zcnt = 0, znow = 1;
            while(num > 0) {
                if(num & 1) {
                    if(now < 'z') s += now;
                    else zcnt += znow;
                }
                num >>= 1;
                if(now < 'z') now++;
                else znow *= 2;
            }
            for(int i = 0; i < zcnt; i++) s += 'z';
            reverse(s.begin(), s.end());
            ans.push_back(s);
        }
        return ans;
    }
};
