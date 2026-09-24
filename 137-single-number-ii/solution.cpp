class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, b = 1;
        while(true) {
            int cnt = 0;
            for(auto& num : nums) cnt += ((num & b) != 0);
            if(cnt % 3 != 0) ans |= b;
            if(b == INT_MIN) break;
            b <<= 1;
        }
        return ans;
    }
};
