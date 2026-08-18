class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(auto& num : nums) {
            string s = to_string(num);
            int d = 0;
            for(auto& c : s) d = max(d, c - '0');
            for(auto& c : s) c = ('0' + d);
            ans += stoi(s);
        }
        return ans;
    }
};
