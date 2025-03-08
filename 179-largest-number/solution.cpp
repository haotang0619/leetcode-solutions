class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string s0 = to_string(a);
            string s1 = to_string(b);
            while(true){
                int n = min(s0.length(), s1.length());
                int diff = s0.length() - s1.length();
                for(int i = 0; i < n; i++) {
                    if(s0[i] < s1[i]) return false;
                    if(s0[i] > s1[i]) return true;
                }
                if(diff == 0) return false;
                if(diff > 0) s0 = s0.substr(s1.length(), diff);
                else s1 = s1.substr(s0.length(), -diff);
            }
        });
        string ans;
        if(nums[0] == 0) return "0";
        for(auto x : nums) ans += to_string(x);
        return ans;
    }
};
