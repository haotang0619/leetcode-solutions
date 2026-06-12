class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto x : nums) {
            if(x == 2) ans.push_back(-1);
            else {
                string s = bitset<32>(x).to_string();
                for(int i = 31; i >= 0; i--) {
                    if(s[i] == '0') {
                        s[i + 1] = '0';
                        break;
                    }
                }
                ans.push_back(stoi(s, NULL, 2));
            }
        }
        return ans;
    }
};
