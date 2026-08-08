class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(auto& num : nums) {
            string s = to_string(num);
            for(auto& c : s) {
                if((c - '0') == digit) ans++;
            }
        }
        return ans;
    }
};
