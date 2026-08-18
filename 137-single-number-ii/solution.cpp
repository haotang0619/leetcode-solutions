// Asked GPT for hints
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, base = 1;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(auto& num : nums) cnt += ((num & base) != 0);
            if(cnt % 3 != 0) ans |= base;
            base <<= 1;
        }
        return ans;
    }
};
